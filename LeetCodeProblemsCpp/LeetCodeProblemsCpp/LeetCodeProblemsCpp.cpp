#include <iostream>

#include "Problems/LeetCode2033MinimumOperationsToMakeAUniValueGrid.h"
#include "Problems/LeetCode2560HouseRobberIV.h"
#include "Problems/LeetCode3394CheckIfGridCanBeCutIntoSections.h"
#include "Problems/LeetCode416PartitionEqualSubsetSum.h"
#include "Problems/LeetCode90SubsetsII.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode416PartitionEqualSubsetSum();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "416. Partition Equal Subset Sum";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
}



