//
// Created by Дарья on 09.12.2020.
//

#ifndef LAB2_SEM5_BRACKET_H
#define LAB2_SEM5_BRACKET_H


#include "Operation.h"

class Bracket: public Operation {
public:
    typedef enum {
        OPEN,
        CLOSE
    } bracketType;
    Bracket(bracketType type);
    bool operateStacks(std::stack<double> &numbers, std::stack<const Operation *> &operations) const override;
    double process(std::vector<double> args) const override;
private:
    bracketType type;
};


#endif //LAB2_SEM5_BRACKET_H
