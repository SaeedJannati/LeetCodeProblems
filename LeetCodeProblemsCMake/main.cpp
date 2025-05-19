#include <iostream>

#include "Auxilary/Auxilaries.h"
#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/GeeksForGeeksTravellingSalesmanProblem.h"
#include "Problems/LeetCode2094Finding3DigitEvenNumbers.h"
#include "Problems/LeetCode260SingleNumberIII.h"
#include "Problems/LeetCode3341FindMinimumTimeToReachLastRoomI.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new GeeksForGeeksTravellingSalesmanProblem();
    problem->Run();
    delete problem;


#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "847. Shortest Path Visiting All Nodes";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[0, 1000, 5000], [5000, 0, 1000], [1000, 5000, 0]]";
  Auxilaries::ConvertToVector(input);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
