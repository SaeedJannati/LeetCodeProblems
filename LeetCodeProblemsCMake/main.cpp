#include <iostream>

#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/LeetCode214ShortestPalindrome.h"
#include "Problems/LeetCode29DivideTwoIntegers.h"
#include "Problems/LeetCode743NetworkDelayTime.h"
#include "Problems/LeetCode980UniquePathsIII.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode980UniquePathsIII();
    problem->Run();
    delete problem;

#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "2661. First Completely Painted Row or Column";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
