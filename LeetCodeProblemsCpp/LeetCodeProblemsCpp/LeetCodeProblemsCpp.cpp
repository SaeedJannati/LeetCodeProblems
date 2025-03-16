#include <iostream>

#include "Problems/LeetCode2560HouseRobberIV.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode2560HouseRobberIV();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "2594. Minimum Time to Repair Cars";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
}
