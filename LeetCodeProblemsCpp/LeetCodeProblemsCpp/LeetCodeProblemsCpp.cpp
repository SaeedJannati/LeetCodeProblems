#include <iostream>

#include "Problems/Auxilaries.h"
#include "Problems/LeetCode1233RemoveSubFoldersFromTheFilesystem.h"
#include "Problems/LeetCode1716CalculateMoneyInLeetcodeBank.h"
#include "Problems/LeetCode2197ReplaceNonCoprimeNumbersInArray.h"
#include "Problems/LeetCode3346MaximumFrequencyOfAnElementAfterPerformingOperationsI.h"
#include "Problems/LeetCode966VowelSpellchecker.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode1716CalculateMoneyInLeetcodeBank();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "2043. Simple Bank System";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[5,9]]";
    Auxilaries::ConvertToVector(input);
#pragma endregion
}



