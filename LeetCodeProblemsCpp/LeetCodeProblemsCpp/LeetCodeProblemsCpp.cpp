#include <iostream>

#include "Problems/LeetCode1233RemoveSubFoldersFromTheFilesystem.h"
#include "Problems/LeetCode2210CountHillsAndValleysInAnArray.h"
#include "Problems/LeetCode2411SmallestSubarraysWithMaximumBitwiseOR.h"
#include "Problems/LeetCode907SumOfSubarrayMinimums.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode2411SmallestSubarraysWithMaximumBitwiseOR();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "2411. Smallest Subarrays With Maximum Bitwise OR";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
}



