#include <iostream>

#include "Auxilary/Auxilaries.h"
#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/LeetCode1948DeleteDuplicateFoldersInSystem.h"
#include "Problems/LeetCode2402MeetingRoomsIII.h"
#include "Problems/LeetCode2561RearrangingFruits.h"
#include "Problems/LeetCode3363FindTheMaximumNumberOfFruitsCollected.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode3363FindTheMaximumNumberOfFruitsCollected();
    problem->Run();
    delete problem;


#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "342. Power of Four";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[1,2,3,4],[5,6,8,7],[9,10,11,12],[13,14,15,16]]";
  Auxilaries::ConvertToVector(input);
#pragma endregion
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
