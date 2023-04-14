#pragma once
#include <string>
#include <cstring>
#include <vector>

namespace StringExtensions
{
    bool Contains(std::string s1, std::string s2);
    std::string RemoveText(std::string text, std::string toRemove);
    std::vector<std::string> Split(std::string text, std::string delimiter);
}