//
// Created by Дарья on 11.12.2020.
//

#ifndef LAB2_SEM5_EXPRESSIONPARSER_H
#define LAB2_SEM5_EXPRESSIONPARSER_H

#include <vector>
#include <string>
#include "../Lexeme/Lexem.h"

class ExpressionParser {
public:
    ExpressionParser(const std::vector<const Lexem *> &_possibleLexems, const std::string& _grammar);
    std::vector<const Lexem *> parse(const std::string expression) const;
private:
    std::vector<std::string> splitString(const std::string &str) const;
    const std::string grammar;
    const std::vector<const Lexem*> possibleLexems;
};


#endif //LAB2_SEM5_EXPRESSIONPARSER_H
