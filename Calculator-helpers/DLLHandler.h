//
// Created by Дарья on 11.12.2020.
//

#ifndef LAB2_SEM5_DLLHANDLER_H
#define LAB2_SEM5_DLLHANDLER_H

#include <string>
#include <windows.h>
#include <vector>

class DLLHandler {
public:
    DLLHandler(const std::string& directory);
    int getSize() const;
    HMODULE getDLL(int index) const;
    ~DLLHandler();

private:
    std::vector<HMODULE> libs;
};


#endif //LAB2_SEM5_DLLHANDLER_H
