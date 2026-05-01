#include <iostream>

#include "Auxilary/Auxilaries.h"
#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/LeetCode1262GreatestSumDivisibleByThree.h"
#include "Problems/LeetCode1391CheckIfThereIsAValidPathInAGrid.h"
#include "Problems/LeetCode1680ConcatenationOfConsecutiveBinaryNumbers.h"
#include "Problems/LeetCode2078TwoFurthestHousesWithDifferentColors.h"
#include "Problems/LeetCode2092FindAllPeopleWithSecret.h"
#include "Problems/LeetCode2110NumberOfSmoothDescentPeriodsOfAStock.h"
#include "Problems/LeetCode2147NumberOfWaysToDivideALongCorridor.h"
#include "Problems/LeetCode2515ShortestDistanceToTargetStringInACircularArray.h"
#include "Problems/LeetCode3583CountSpecialTriplets.h"
#include "Problems/LeetCode3742MaximumPathScoreInAGrid.h"
#include "Problems/LeetCode3783MirrorDistanceOfAnInteger.h"
#include "Problems/LeetCode396RotateFunction.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode396RotateFunction();
    problem->Run();
    delete problem;



#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "396. Rotate Function";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[0, 1],[2, 0]";
  Auxilaries::ConvertToVector(input);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
