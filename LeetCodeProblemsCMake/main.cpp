#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/LeetCode2559CountVowelStringsInRanges.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode2559CountVowelStringsInRanges();
    problem->Run();
    delete problem;

#pragma  region  print script name
    std::string scriptName = "2559. Count Vowel Strings in Ranges";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
