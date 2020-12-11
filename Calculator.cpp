//
// Created by Дарья on 09.12.2020.
//

#include <cmath>
#include <utility>
#include "Calculator.h"
#include "Lexeme/Number.h"
#include "Lexeme/Operations/Bracket.h"
#include "Lexeme/Operations/Summation.h"
#include "Lexeme/Operations/Multiplication.h"
#include "Calculator-helpers/ExpressionParser.h"

Calculator::Calculator(const std::string &libsDirectory, std::string  _splitter) : hDll(libsDirectory), splitter(std::move(_splitter)) {
    loadGrammar();
}

void Calculator::loadGrammar() {
    // default "operations":
    possibleLexems.push_back(new Number);
    possibleLexems.push_back(new Bracket(Bracket::OPEN));
    possibleLexems.push_back(new Bracket(Bracket::CLOSE));
    possibleLexems.push_back(new Summation);
    possibleLexems.push_back(new Multiplication);

    // load possible grammar from dll
    for (int i = 0; i < hDll.getSize(); ++i) {
        FARPROC fun = GetProcAddress(hDll.getDLL(i), "getInstance");
        possibleLexems.push_back(reinterpret_cast<Operation*>(fun()));
    }
}

double Calculator::calculate(std::string expression) const{
    ExpressionParser parser(possibleLexems, splitter);
    std::vector<const Lexem *> lexems = parser.parse(expression);
    std::stack<double> numbers;
    std::stack<const Operation*> operations;
    for (const auto &lexem : lexems) {
        if(!lexem->operateStacks(numbers, operations))
            return NAN;
    }
    while (!operations.empty()) {
        operations.top()->runProcess(numbers);
        operations.pop();
    }

    if (numbers.empty() || numbers.size() != 1)
        return NAN;
    return numbers.top();
}

Calculator::~Calculator() {
    for (const auto &lexem : possibleLexems) {
        delete(lexem);
    }
}
