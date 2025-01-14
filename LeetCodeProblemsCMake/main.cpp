#include <iostream>

#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/LeetCode1404NumberOfStepsToReduceANumberInBinaryRepresentationToOne.h"
#include "Problems/LeetCode1443MinimumTimeToCollectAllApplesInATree.h"
#include "Problems/LeetCode204CountPrimes.h"
#include "Problems/LeetCode2657FindThePrefixCommonArrayOfTwoArrays.h"
#include "Problems/LeetCode916WordSubsets.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode2657FindThePrefixCommonArrayOfTwoArrays();
    problem->Run();
    delete problem;

#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "109. Convert Sorted List to Binary Search Tree";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
