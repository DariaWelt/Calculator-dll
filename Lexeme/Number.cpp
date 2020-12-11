//
// Created by Дарья on 09.12.2020.
//

#include <string>
#include "Number.h"

Number::Number(double _value) : value(_value) {}
bool Number::operateStacks(std::stack<double> &numbers, std::stack<const Operation *> &operations) const {
    numbers.push(value);
    return true;
}

Number::Number(): value(0) {}

const Lexem * Number::constructInstance(const std::string &expression)const {
    Number* number = nullptr;
    try {
        double val = std::stod(expression);
        number = new Number(val);
    } catch (std::exception& e) {}
    return number;
}
