//
// Created by Дарья on 11.12.2020.
//

#ifndef LAB2_SEM5_SINUSOPERATION_H
#define LAB2_SEM5_SINUSOPERATION_H


#include "../header.h"

class SinusOperation : public UnaryOperation {
public:
    SinusOperation();
    double process(std::vector<double> args) const override;
};

extern "C"
__declspec (dllexport) Operation* getInstance() {
    return new SinusOperation();
}

#endif //LAB2_SEM5_SINUSOPERATION_H
