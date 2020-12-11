//
// Created by Дарья on 09.12.2020.
//

#ifndef LAB2_SEM5_SUMMATION_H
#define LAB2_SEM5_SUMMATION_H


#include "..\..\header.h"

class Summation: public BinaryOperation {
public:
    Summation();
    double process(std::vector<double> args) const override;
};


#endif //LAB2_SEM5_SUMMATION_H
