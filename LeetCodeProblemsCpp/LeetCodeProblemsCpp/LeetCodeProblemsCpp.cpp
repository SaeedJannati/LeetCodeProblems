#include <iostream>

#include "Problems/LeetCode1233RemoveSubFoldersFromTheFilesystem.h"
#include "Problems/LeetCode2210CountHillsAndValleysInAnArray.h"
#include "Problems/LeetCode907SumOfSubarrayMinimums.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode2210CountHillsAndValleysInAnArray();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "2044. Count Number of Maximum Bitwise-OR Subsets";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
}



