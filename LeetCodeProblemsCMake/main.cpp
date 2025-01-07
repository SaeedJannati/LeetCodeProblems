#include <iostream>

#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/LeetCode184Sum.h"
#include "Problems/LeetCode1930UniqueLength3PalindromicSubsequences.h"
#include "Problems/LeetCode44WildcardMatching.h"
#include "Problems/LeetCode47PermutationsII.h"
#include "Problems/LeetCode60PermutationSequence.h"
#include "Problems/LeetCode65ValidNumber.h"
#include "Problems/LeetCode83RemoveDuplicatesFromSortedList.h"
#include "Problems/LeetCode85MaximalRectangle.h"
#include "Problems/LeetCode881BoatsToSavePeople.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode85MaximalRectangle();
    problem->Run();
    delete problem;

#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "85. Maximal Rectangle";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
