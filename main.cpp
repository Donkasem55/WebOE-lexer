#include "parser.h"
#include "clib/concatenate.hpp"
#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
    std::vector<std::string> args;
    for (int i=2; i<argc; i++) {
        args.push_back(argv[i]);
    }
    std::string argstr = concatenate(args);
    char *y = new char[argstr.length() + 1];
    std::strcpy(y, argstr.c_str());
    if (std::strcmp(argv[1], "-d") == 0) {
        output(y);
    } else if (std::strcmp(argv[1], "-f") == 0) {
        std::ifstream file(argstr);
        if (file.is_open()) {
            std::string temp;
            temp.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            file.close();
            char *z = new char[temp.length() + 1];
            std::strcpy(y, temp.c_str());
            output(z);
        }
    }
    delete[] y;
    return 0;
}
