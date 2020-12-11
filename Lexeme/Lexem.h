//
// Created by Дарья on 09.12.2020.
//

#ifndef LAB2_SEM5_LEXEM_H
#define LAB2_SEM5_LEXEM_H

#include <stack>

class Operation;
class Lexem {
public:
    virtual bool operateStacks(std::stack<double> &numbers, std::stack<const Operation *> &operations) const = 0;
    virtual const Lexem * constructInstance(const std::string& expression) const = 0;
    virtual ~Lexem() = default;
protected:
    Lexem() {};
};


#endif //LAB2_SEM5_LEXEM_H
