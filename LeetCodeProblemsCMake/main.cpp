#include <iostream>

#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/LeetCode140WordBreakII.h"
#include "Problems/LeetCode154FindMinimumInRotatedSortedArrayII.h"
#include "Problems/LeetCode184Sum.h"
#include "Problems/LeetCode2185CountingWordsWithAGivenPrefix.h"
#include "Problems/LeetCode2429MinimizeXOR.h"
#include "Problems/LeetCode2683NeighboringBitwiseXOR.h"
#include "Problems/LeetCode29DivideTwoIntegers.h"
#include "Problems/LeetCode43MultiplyStrings.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode29DivideTwoIntegers();
    problem->Run();
    delete problem;

#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "29. Divide Two Integers";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
