//
// Created by Дарья on 11.12.2020.
//

#include "ExpressionParser.h"

ExpressionParser::ExpressionParser(const std::vector<const Lexem *> &_possibleLexems, const std::string& _grammar): possibleLexems(_possibleLexems), grammar(_grammar) {}

std::vector<const Lexem *> ExpressionParser::parse(const std::string expression) const {
    std::vector<std::string> substrings = splitString(expression);
    std::vector<const Lexem *> result;
    for (const auto &substring : substrings) {
        const Lexem* instance;
        for (const auto &possibleLexem : possibleLexems) {
            if ((instance = possibleLexem->constructInstance(substring)) != nullptr)
                break;
        }
        if (instance == nullptr) {
            return {nullptr};
        }
        result.push_back(instance);
    }
    return result;
}

std::vector<std::string> ExpressionParser::splitString(const std::string &str) const {
    size_t currentPos = 0, lastPos = 0;
    std::string substring;
    std::vector<std::string> result;
    while (lastPos < str.size()) {
        currentPos = str.find(grammar, lastPos);
        if (currentPos == std::string::npos)
            currentPos = str.size();
        substring = str.substr(lastPos, currentPos - lastPos);
        lastPos = currentPos + grammar.size();
        result.push_back(substring);
    }
    return result;
}
