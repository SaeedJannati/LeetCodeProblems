#include <iostream>

#include "Auxilary/Auxilaries.h"
#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/LeetCode1774ClosestDessertCost.h"
#include "Problems/LeetCode1948DeleteDuplicateFoldersInSystem.h"
#include "Problems/LeetCode2402MeetingRoomsIII.h"
#include "Problems/LeetCode2561RearrangingFruits.h"
#include "Problems/LeetCode2749MinimumOperationsToMakeTheIntegerZero.h"
#include "Problems/LeetCode3363FindTheMaximumNumberOfFruitsCollected.h"
#include "Problems/LeetCode3392CountSubarraysOfLengthThreeWithACondition.h"
#include "Problems/LeetCode3446SortMatrixByDiagonals.h"
#include "Problems/LeetCode421MaximumXOROfTwoNumbersInAnArray.h"
#include "Problems/LeetCode475Heaters.h"
#include "Problems/LeetCode67924Game.h"
#include "Problems/LeetCode837New21Game.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode1774ClosestDessertCost();
    problem->Run();
    delete problem;


#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "1774. Closest Dessert Cost";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[8,2,3],[9,1,7],[4,5,6]]";
  Auxilaries::ConvertToVector(input);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
