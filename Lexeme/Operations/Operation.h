//
// Created by Дарья on 08.12.2020.
//

#ifndef LAB2_SEM5_OPERATION_H
#define LAB2_SEM5_OPERATION_H

#include <string>
#include <vector>
#include "..\Lexem.h"

class Operation: public Lexem {
public:
    bool operateStacks(std::stack<double> &numbers, std::stack<const Operation *> &operations) const override;
    int getArgumentsNum() const;
    virtual double process(std::vector<double> args) const = 0;
    std::string getGrammar() const;
    int getPriority() const;
    bool runProcess(std::stack<double> &numbers) const;
    const Lexem * constructInstance(const std::string &expression) const override;
protected:
    Operation(const std::string& _grammar, int _priority, int _argsNum) : grammar(_grammar), priority(_priority), argsNum(_argsNum){};
    const int argsNum;
    const std::string grammar;
    const int priority;
};

#endif //LAB2_SEM5_OPERATION_H
