//
// Created by Дарья on 09.12.2020.
//

#ifndef LAB2_SEM5_NUMBER_H
#define LAB2_SEM5_NUMBER_H


#include "Lexem.h"

class Number: public Lexem {
public:
    Number();
    const Lexem * constructInstance(const std::string &expression) const override;
    bool operateStacks(std::stack<double> &numbers, std::stack<const Operation *> &operations) const override;
private:
    Number(double _value);
    double value;
};


#endif //LAB2_SEM5_NUMBER_H
