#include <iostream>

#include "Auxilary/Auxilaries.h"
#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/GeeksForGeeksAlienDictionary.h"
#include "Problems/LeetCode1980FindUniqueBinaryString.h"
#include "Problems/LeetCode241DifferentWaysToAddParentheses.h"
#include "Problems/LeetCode264UglyNumberII.h"
#include "Problems/LeetCode2965FindMissingAndRepeatedValues.h"
#include "Problems/LeetCode3160FindTheNumberOfDistinctColorsAmongTheBalls.h"
#include "Problems/LeetCode3208AlternatingGroupsII.h"
#include "Problems/LeetCode3356ZeroArrayTransformationII.h"
#include "Problems/LeetCode390EliminationGame.h"
#include "Problems/LeetCode684RedundantConnection.h"
#include "Problems/LeetCode873LengthOfLongestFibonacciSubsequence.h"

#include "Problems/LeetCode89GrayCode.h"
#include "Problems/LeetCode96UniqueBinarySearchTrees.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode3356ZeroArrayTransformationII();
    problem->Run();
    delete problem;


#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "3356. Zero Array Transformation II";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[0,0,3],[0,0,2],[0,0,2],[0,0,5],[0,0,3],[0,0,4],[0,0,4],[0,0,3],[0,0,5],[0,0,4],[0,0,5],[0,0,3],[0,0,4],[0,0,1],[0,0,1]]";
  Auxilaries::ConvertToVector(input);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
