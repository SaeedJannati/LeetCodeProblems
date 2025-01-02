#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/LeetCode2138DivideAStringIntoGroupsOfSizeK.h"
#include "Problems/LeetCode2559CountVowelStringsInRanges.h"
#include "Problems/LeetCode40CombinationSumII.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode40CombinationSumII();
    problem->Run();
    delete problem;

#pragma  region  print script name
    std::string scriptName = "40. Combination Sum II";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
