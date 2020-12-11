//
// Created by Дарья on 11.12.2020.
//

#include "Powering.h"
#include <cmath>

Powering::Powering(): BinaryOperation("^", 0) {}

double Powering::process(std::vector<double> args) const {
    return pow(args[1],args[0]);
}

