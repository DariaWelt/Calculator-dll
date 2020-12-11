//
// Created by Дарья on 09.12.2020.
//

#ifndef LAB2_SEM5_MULTIPLICATION_H
#define LAB2_SEM5_MULTIPLICATION_H

#include "../../header.h"

class Multiplication: public BinaryOperation {
public:
    Multiplication();
    double process(std::vector<double> args) const override;
};


#endif //LAB2_SEM5_MULTIPLICATION_H
