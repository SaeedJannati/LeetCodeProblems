#include <iostream>

#include "Problems/Auxilaries.h"
#include "Problems/LeetCode1233RemoveSubFoldersFromTheFilesystem.h"
#include "Problems/LeetCode1942TheNumberOfTheSmallestUnoccupiedChair.h"
#include "Problems/LeetCode3025FindTheNumberOfWaysToPlacePeopleI.h"
#include "Problems/LeetCode3495MinimumOperationsToMakeArrayElementsZero.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode3495MinimumOperationsToMakeArrayElementsZero();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "1304. Find N Unique Integers Sum up to Zero";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[5,9]]";
    Auxilaries::ConvertToVector(input);
#pragma endregion
}



