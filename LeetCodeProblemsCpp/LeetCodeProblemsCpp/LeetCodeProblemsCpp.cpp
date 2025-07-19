#include <iostream>

#include "Problems/LeetCode1233RemoveSubFoldersFromTheFilesystem.h"
#include "Problems/LeetCode1922CountGoodNumbers.h"
#include "Problems/LeetCode2033MinimumOperationsToMakeAUniValueGrid.h"
#include "Problems/LeetCode2560HouseRobberIV.h"
#include "Problems/LeetCode3201FindTheMaximumLengthOfValidSubsequenceI.h"
#include "Problems/LeetCode3394CheckIfGridCanBeCutIntoSections.h"
#include "Problems/LeetCode3396MinimumNumberOfOperationsToMakeElementsInArrayDistinct.h"
#include "Problems/LeetCode416PartitionEqualSubsetSum.h"
#include "Problems/LeetCode781RabbitsInForest.h"
#include "Problems/LeetCode90SubsetsII.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode1233RemoveSubFoldersFromTheFilesystem();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "1233. Remove Sub-Folders from the Filesystem";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
}



