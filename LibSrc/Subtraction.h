//
// Created by Дарья on 11.12.2020.
//

#ifndef LAB2_SEM5_SUBTRACTION_H
#define LAB2_SEM5_SUBTRACTION_H

#include "..\header.h"

class Subtraction : public BinaryOperation {
public:
    Subtraction();
    double process(std::vector<double> args) const override;
};

extern "C"
__declspec (dllexport) Operation* getInstance() {
    return new Subtraction();
}

#endif //LAB2_SEM5_SUBTRACTION_H
