#pragma once
#include <string>
#include <vector>

class Auxilaries
{
public:
    static  void PrintVector(std::vector<int>& vector);
    static void PrintVector(std::vector<std::vector<int>>& vector);
    static void ConvertToVector(std::string &str);

};
