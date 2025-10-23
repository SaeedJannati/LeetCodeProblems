#include <iostream>

#include "Auxilary/Auxilaries.h"
#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/LeetCode1432MaxDifferenceYouCanGetFromChangingAnInteger.h"
#include "Problems/LeetCode1488AvoidFloodInTheCity.h"
#include "Problems/LeetCode1834SingleThreadedCPU.h"
#include "Problems/LeetCode1948DeleteDuplicateFoldersInSystem.h"
#include "Problems/LeetCode2221FindTriangularSumOfAnArray.h"
#include "Problems/LeetCode2598SmallestMissingNonnegativeIntegerAfterOperations.h"
#include "Problems/LeetCode3186MaximumTotalDamageWithSpellCasting.h"
#include "Problems/LeetCode3349AdjacentIncreasingSubarraysDetectionI.h"
#include "Problems/LeetCode3461CheckIfDigitsAreEqualInStringAfterOperationsI.h"
#include "Problems/LeetCode3603MinimumCostPathWithAlternatingDirectionsII.h"
#include "Problems/LeetCode621TaskScheduler.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode3461CheckIfDigitsAreEqualInStringAfterOperationsI();
    problem->Run();
    delete problem;


#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "3461. Check If Digits Are Equal in String After Operations I";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[1,2],[2,4],[3,2],[4,1]]";
  Auxilaries::ConvertToVector(input);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
