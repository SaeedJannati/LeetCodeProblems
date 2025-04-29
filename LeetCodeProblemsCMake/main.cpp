#include <iostream>

#include "Auxilary/Auxilaries.h"
#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/LeetCode2302CountSubarraysWithScoreLessThanK.h"
#include "Problems/LeetCode2444CountSubarraysWithFixedBounds.h"
#include "Problems/LeetCode2799CountCompleteSubarraysInAnArray.h"
#include "Problems/LeetCode2845CountOfInterestingSubarrays.h"
#include "Problems/LeetCode2962CountSubarraysWhereMaxElementAppearsAtLeastKTimes.h"
#include "Problems/LeetCode3392CountSubarraysOfLengthThreeWithACondition.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode2962CountSubarraysWhereMaxElementAppearsAtLeastKTimes();
    problem->Run();
    delete problem;


#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "2962. Count Subarrays Where Max Element Appears at Least K Times";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[3,2],[4,3],[4,4],[2,5]]";
  Auxilaries::ConvertToVector(input);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
