// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype> 

unsigned int faStr1(const char *str) {
    if (str == nullptr) return 0;
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;

    for (const char* p = str; ; ++p) {
        char ch = *p;
        bool isSpace = std::isspace(static_cast<unsigned char>(ch));

        if (isSpace || ch == '\0') {
            if (inWord) {
                if (!hasDigit) {
                    ++count;
                }
                inWord = false;
                hasDigit = false;
            }
            if (ch == '\0') break;
        } else {
            if (!inWord) {
                inWord = true;
                hasDigit = false;
            }
            if (std::isdigit(static_cast<unsigned char>(ch))) {
                hasDigit = true;
            }
        }
    }
    return count;
}

unsigned int faStr2(const char *str) {
    return 0;
}

unsigned int faStr3(const char *str) {
    return 0;
}
