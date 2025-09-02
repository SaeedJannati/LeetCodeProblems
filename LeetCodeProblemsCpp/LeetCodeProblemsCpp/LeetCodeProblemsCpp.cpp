#include <iostream>

#include "Problems/Auxilaries.h"
#include "Problems/LeetCode1233RemoveSubFoldersFromTheFilesystem.h"
#include "Problems/LeetCode1942TheNumberOfTheSmallestUnoccupiedChair.h"
#include "Problems/LeetCode3025FindTheNumberOfWaysToPlacePeopleI.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode3025FindTheNumberOfWaysToPlacePeopleI();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "3025. Find the Number of Ways to Place People I";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[0,1],[5,2]]";
    Auxilaries::ConvertToVector(input);
#pragma endregion
}



