#include <iostream>

#include "Problems/Auxilaries.h"
#include "Problems/LeetCode1233RemoveSubFoldersFromTheFilesystem.h"
#include "Problems/LeetCode2197ReplaceNonCoprimeNumbersInArray.h"
#include "Problems/LeetCode966VowelSpellchecker.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode2197ReplaceNonCoprimeNumbersInArray();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "2011. Final Value of Variable After Performing Operations";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[5,9]]";
    Auxilaries::ConvertToVector(input);
#pragma endregion
}



