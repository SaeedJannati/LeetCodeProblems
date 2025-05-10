#include <iostream>

#include "Auxilary/Auxilaries.h"
#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/LeetCode1128NumberOfEquivalentDominoPairs.h"
#include "Problems/LeetCode1295FindNumbersWithEvenNumberOfDigits.h"
#include "Problems/LeetCode2302CountSubarraysWithScoreLessThanK.h"
#include "Problems/LeetCode2444CountSubarraysWithFixedBounds.h"
#include "Problems/LeetCode2799CountCompleteSubarraysInAnArray.h"
#include "Problems/LeetCode2845CountOfInterestingSubarrays.h"
#include "Problems/LeetCode2962CountSubarraysWhereMaxElementAppearsAtLeastKTimes.h"
#include "Problems/LeetCode3341FindMinimumTimeToReachLastRoomI.h"
#include "Problems/LeetCode3392CountSubarraysOfLengthThreeWithACondition.h"
#include "Problems/LeetCode838PushDominoes.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode3341FindMinimumTimeToReachLastRoomI();
    problem->Run();
    delete problem;


#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "2918. Minimum Equal Sum of Two Arrays After Replacing Zeros";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[0,4],[4,4]]";
  Auxilaries::ConvertToVector(input);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
