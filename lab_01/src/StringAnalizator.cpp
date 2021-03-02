//
// Created by denis on 28.02.2021.
//

#include "StringAnalizator.h"
#include "regex"

bool IsInt(const std::string& str)
{
    auto intCheck = std::regex("[\\d]+");
    return std::regex_match(str, intCheck);
}
