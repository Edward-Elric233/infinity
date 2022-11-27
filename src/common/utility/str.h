//
// Created by JinHai on 2022/7/20.
//

#pragma once

#include <string>
#include <algorithm>
#include <cctype>
#include <locale>

namespace infinity {

// trim path string "/absolute/path/src/module/abc.h" into "module/abc.h"
std::string
TrimPath(const std::string& path);

// trim from start (in place)
inline void
ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch) && (ch != '\0');
    }));
}

// trim from end (in place)
inline void
rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch) && (ch != '\0');
    }).base(), s.end());
}

// trim from both ends (in place)
inline void
trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

}
