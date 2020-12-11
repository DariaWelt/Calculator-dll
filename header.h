//
// Created by Дарья on 09.12.2020.
//

#ifndef LAB2_SEM5_HEADER_H
#define LAB2_SEM5_HEADER_H

#include "Lexeme/Operations/Operation.h"

class BinaryOperation: public Operation {
protected:
    BinaryOperation(std::string _grammar, int _priority): Operation(_grammar, _priority, 2) {};
};

class UnaryOperation: public Operation {
protected:
    UnaryOperation(std::string _grammar, int _priority): Operation(_grammar, _priority, 1)  {};
};
#endif //LAB2_SEM5_HEADER_H
