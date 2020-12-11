//
// Created by Дарья on 11.12.2020.
//

#include "DLLHandler.h"

#include <filesystem>
#include <fstream>
#include <ctime>

DLLHandler::DLLHandler(const std::string &directory) {
    std::ofstream log;
    log.open("Logging.txt");
    try {
        for (auto &file : std::filesystem::directory_iterator(directory)) {
            if (file.is_directory() || file.path().extension() != ".dll") continue;
            HMODULE hDll = LoadLibrary(file.path().string().c_str());
            if (hDll == nullptr) {
                std::time_t time = std::time(0);
                log << puts(ctime(&time)) << "Error: can not load dll: %s" << file.path().string() << std::endl;
                continue;
            } else
                libs.push_back(hDll);
        }
        log.close();
    } catch (std::exception) {
        std::time_t time = std::time(0);
        log << asctime(localtime(&time)) << " Error: can not load dlls - wrong path to dll's directory"<< std::endl;
        log.close();
        return;
    }
}

DLLHandler::~DLLHandler() {
    for (const auto &lib : libs) {
        FreeLibrary(lib);
    }
}

int DLLHandler::getSize() const {
    return libs.size();
}

HMODULE DLLHandler::getDLL(int index) const {
    if (index >= 0 && index < libs.size())
        return libs[index];
    return nullptr;
}