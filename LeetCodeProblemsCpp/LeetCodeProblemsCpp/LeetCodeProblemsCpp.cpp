#include <iostream>

#include "Problems/Auxilaries.h"
#include "Problems/LeetCode1233RemoveSubFoldersFromTheFilesystem.h"
#include "Problems/LeetCode1942TheNumberOfTheSmallestUnoccupiedChair.h"
#include "Problems/LeetCode3025FindTheNumberOfWaysToPlacePeopleI.h"
#include "Problems/LeetCode3495MinimumOperationsToMakeArrayElementsZero.h"
#include "Problems/LeetCode966VowelSpellchecker.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode966VowelSpellchecker();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "3227. Vowels Game in a String";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[5,9]]";
    Auxilaries::ConvertToVector(input);
#pragma endregion
}



