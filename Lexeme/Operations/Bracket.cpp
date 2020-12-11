//
// Created by Дарья on 09.12.2020.
//

#include "Bracket.h"

Bracket::Bracket(Bracket::bracketType type) : Operation(type == OPEN ? "(" : ")", INT_MAX, 0), type(type) {}

bool Bracket::operateStacks(std::stack<double> &numbers, std::stack<const Operation *> &operations) const {
    if (type == OPEN) {
        operations.push(this);
        return true;
    }
    const Operation* currentOp;
    bool isFine = true;
    while (!operations.empty() && (currentOp = operations.top())->getPriority() != INT_MAX ) {
        operations.pop(); // ??????????????????????
        isFine = currentOp->runProcess(numbers);
        if (isFine != true)
            return false;
    }
    operations.pop();
    return true;
}

double Bracket::process(std::vector<double> args) const {
    return 0;
}

