//
// Created by Дарья on 11.12.2020.
//

#ifndef LAB2_SEM5_POWERING_H
#define LAB2_SEM5_POWERING_H

#include "../header.h"

class Powering : public BinaryOperation {
public:
    Powering();
    double process(std::vector<double> args) const override;
};

extern "C"
__declspec (dllexport) Operation* getInstance() {
    return new Powering();
}

#endif //LAB2_SEM5_POWERING_H
