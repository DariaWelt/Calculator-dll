//
// Created by Дарья on 09.12.2020.
//

#ifndef LAB2_SEM5_CALCULATOR_H
#define LAB2_SEM5_CALCULATOR_H

#include <string>
#include "Calculator-helpers/DLLHandler.h"
#include "Lexeme/Lexem.h"

class Calculator {
public:
    Calculator(const std::string &libsDirectory, std::string  _splitter = " ");
    double calculate(std::string expression) const;

    virtual ~Calculator();

private:
    void loadGrammar();
    std::vector<const Lexem*> possibleLexems;
    const std::string splitter;
    DLLHandler hDll;

};


#endif //LAB2_SEM5_CALCULATOR_H
