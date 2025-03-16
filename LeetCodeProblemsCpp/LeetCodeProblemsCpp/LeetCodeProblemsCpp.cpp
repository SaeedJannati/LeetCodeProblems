#include <iostream>

#include "Problems/LeetCode2560HouseRobberIV.h"
#include "Problems/LeetCode90SubsetsII.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode90SubsetsII();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "90. Subsets II";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
}
