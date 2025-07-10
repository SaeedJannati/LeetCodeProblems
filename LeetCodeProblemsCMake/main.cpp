#include <iostream>

#include "Auxilary/Auxilaries.h"
#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/LeetCode1353MaximumNumberOfEventsThatCanBeAttended.h"
#include "Problems/LeetCode1498NumberOfSubsequencesThatSatisfyTheGivenSumCondition.h"
#include "Problems/LeetCode187RepeatedDNASequences.h"
#include "Problems/LeetCode2359FindClosestNodeToGivenTwoNodes.h"
#include "Problems/LeetCode2929DistributeCandiesAmongChildrenII.h"
#include "Problems/LeetCode3170LexicographicallyMinimumStringAfterRemovingStars.h"
#include "Problems/LeetCode3304FindTheKthCharacterInStringGameI.h"
#include "Problems/LeetCode3333FindTheOriginalTypedStringII.h"
#include "Problems/LeetCode3373MaximizeTheNumberOfTargetNodesAfterConnectingTreesII.h"
#include "Problems/LeetCode3403FindTheLexicographicallyLargestStringFromTheBoxI.h"
#include "Problems/LeetCode3440RescheduleMeetingsForMaximumFreeTimeII.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode3440RescheduleMeetingsForMaximumFreeTimeII();
    problem->Run();
    delete problem;


#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "3440. Reschedule Meetings for Maximum Free Time II";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[1,2],[1,2],[1,6],[1,2],[1,2]]";
  Auxilaries::ConvertToVector(input);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
