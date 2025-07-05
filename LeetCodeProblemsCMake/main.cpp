#include <iostream>

#include "Auxilary/Auxilaries.h"
#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/LeetCode1498NumberOfSubsequencesThatSatisfyTheGivenSumCondition.h"
#include "Problems/LeetCode187RepeatedDNASequences.h"
#include "Problems/LeetCode2359FindClosestNodeToGivenTwoNodes.h"
#include "Problems/LeetCode2929DistributeCandiesAmongChildrenII.h"
#include "Problems/LeetCode3170LexicographicallyMinimumStringAfterRemovingStars.h"
#include "Problems/LeetCode3304FindTheKthCharacterInStringGameI.h"
#include "Problems/LeetCode3333FindTheOriginalTypedStringII.h"
#include "Problems/LeetCode3373MaximizeTheNumberOfTargetNodesAfterConnectingTreesII.h"
#include "Problems/LeetCode3403FindTheLexicographicallyLargestStringFromTheBoxI.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode3304FindTheKthCharacterInStringGameI();
    problem->Run();
    delete problem;


#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "1394. Find Lucky Integer in an Array";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]";
  Auxilaries::ConvertToVector(input);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
