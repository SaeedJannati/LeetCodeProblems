#include <iostream>

#include "Problems/LeetCode2560HouseRobberIV.h"
#include "Problems/LeetCode3394CheckIfGridCanBeCutIntoSections.h"
#include "Problems/LeetCode90SubsetsII.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode3394CheckIfGridCanBeCutIntoSections();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "3394. Check if Grid can be Cut into Sections";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
}



