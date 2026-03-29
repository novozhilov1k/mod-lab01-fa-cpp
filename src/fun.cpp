// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cstring>
#include <cmath>
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
    if (!str) return 0;
    unsigned int count = 0;
    const char *p = str;
    while (true) {
        while (*p && std::isspace(static_cast<unsigned char>(*p))) ++p;
        if (!*p) break;
        const char *start = p;
        while (*p && !std::isspace(static_cast<unsigned char>(*p))) ++p;
        unsigned int wlen = static_cast<unsigned int>(p - start);
        if (wlen == 0) continue;
        bool ok = true;
        char first = start[0];
        if (!(first >= 'A' && first <= 'Z')) ok = false;
        for (const char *q = start + 1; q < p; ++q) {
            char ch = *q;
            if (!(ch >= 'a' && ch <= 'z')) {
                ok = false;
                break;
            }
        }
        if (ok) ++count;
    }
    return count;
}
unsigned int faStr3(const char *str) {
    if (str == nullptr) return 0;
    int totalLength = 0;
    int wordCount = 0;
    int currentLength = 0;
    bool inWord = false;
    for (; *str != '\0'; ++str) {
        if (!isspace((unsigned char)*str)) {
            inWord = true;
            currentLength++;
        } else {
            if (inWord) {
                wordCount++;
                totalLength += currentLength;
                currentLength = 0;
                inWord = false;
            }
        }
    }
    if (inWord) {
        wordCount++;
        totalLength += currentLength;
    }

    if (wordCount == 0) return 0;
    double average = static_cast<double>totalLength / wordCount;
    return static_cas<unsigned int>round(average);
}
