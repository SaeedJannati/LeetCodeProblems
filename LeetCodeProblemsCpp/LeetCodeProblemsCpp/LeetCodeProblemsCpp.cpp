#include <iostream>

#include "Problems/Auxilaries.h"
#include "Problems/LeetCode1233RemoveSubFoldersFromTheFilesystem.h"
#include "Problems/LeetCode1942TheNumberOfTheSmallestUnoccupiedChair.h"
#include "Problems/LeetCode498DiagonalTraverse.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode1942TheNumberOfTheSmallestUnoccupiedChair();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "1942. The Number of the Smallest Unoccupied Chair";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[99999,100000],[1,2]]";
    Auxilaries::ConvertToVector(input);
#pragma endregion
}



