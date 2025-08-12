#include <iostream>

#include "Problems/Auxilaries.h"
#include "Problems/LeetCode1233RemoveSubFoldersFromTheFilesystem.h"
#include "Problems/LeetCode2438RangeProductQueriesOfPowers.h"
#include "Problems/LeetCode2787WaysToExpressAnIntegerAsSumOfPowers.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode2787WaysToExpressAnIntegerAsSumOfPowers();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "2787. Ways to Express an Integer as Sum of Powers";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[0,1],[2,2],[0,3]]";
    Auxilaries::ConvertToVector(input);
#pragma endregion
}



