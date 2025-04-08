#include <iostream>

#include "Problems/LeetCode2033MinimumOperationsToMakeAUniValueGrid.h"
#include "Problems/LeetCode2560HouseRobberIV.h"
#include "Problems/LeetCode3394CheckIfGridCanBeCutIntoSections.h"
#include "Problems/LeetCode3396MinimumNumberOfOperationsToMakeElementsInArrayDistinct.h"
#include "Problems/LeetCode416PartitionEqualSubsetSum.h"
#include "Problems/LeetCode90SubsetsII.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode3396MinimumNumberOfOperationsToMakeElementsInArrayDistinct();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "3396. Minimum Number of Operations to Make Elements in Array Distinct";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
}



