#include <iostream>

#include "Problems/LeetCode1233RemoveSubFoldersFromTheFilesystem.h"
#include "Problems/LeetCode907SumOfSubarrayMinimums.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode907SumOfSubarrayMinimums();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "907. Sum of Subarray Minimums";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
}



