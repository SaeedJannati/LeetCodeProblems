#include <iostream>

#include "Problems/LeetCode1233RemoveSubFoldersFromTheFilesystem.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode1233RemoveSubFoldersFromTheFilesystem();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "1717. Maximum Score From Removing Substrings";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
}



