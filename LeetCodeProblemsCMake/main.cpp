#include <iostream>

#include "Auxilary/Auxilaries.h"
#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/GeeksForGeeksAlienDictionary.h"
#include "Problems/LeetCode1980FindUniqueBinaryString.h"
#include "Problems/LeetCode241DifferentWaysToAddParentheses.h"
#include "Problems/LeetCode264UglyNumberII.h"
#include "Problems/LeetCode2965FindMissingAndRepeatedValues.h"
#include "Problems/LeetCode3160FindTheNumberOfDistinctColorsAmongTheBalls.h"
#include "Problems/LeetCode390EliminationGame.h"
#include "Problems/LeetCode684RedundantConnection.h"
#include "Problems/LeetCode873LengthOfLongestFibonacciSubsequence.h"

#include "Problems/LeetCode89GrayCode.h"
#include "Problems/LeetCode96UniqueBinarySearchTrees.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode2965FindMissingAndRepeatedValues();
    problem->Run();
    delete problem;


#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "2379. Minimum Recolors to Get K Consecutive Black Blocks";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[9,1,7],[8,9,2],[3,4,6]]";
  Auxilaries::ConvertToVector(input);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
