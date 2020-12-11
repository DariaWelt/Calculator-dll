//
// Created by Дарья on 09.12.2020.
//

#include <cmath>
#include "..\..\header.h"
#include "Operation.h"




int Operation::getArgumentsNum() const {
    return argsNum;
}

int Operation::getPriority() const {
    return priority;
}

std::string Operation::getGrammar() const {
    return grammar;
}

bool Operation::operateStacks(std::stack<double> &numbers, std::stack<const Operation *> &operations) const {
    const Operation* currentOp;
    while (!operations.empty() && (currentOp = operations.top())->getPriority() < priority){
        if (!currentOp->runProcess(numbers))
            return false;
        operations.pop();
    }
    operations.push(this);
    return true;
}

const Lexem *Operation::constructInstance(const std::string &expression) const {
    return expression == grammar ? this : nullptr;
}

bool Operation::runProcess(std::stack<double> &numbers) const {
    std::vector<double> args;
    while (!numbers.empty() && args.size() < argsNum){
        args.push_back(numbers.top());
        numbers.pop();
    }
    if (args.size() != argsNum) {
        return false;
    }
    double result = process(args);
    if (result != result)
        return false;
    numbers.push(result);
    return true;
}
