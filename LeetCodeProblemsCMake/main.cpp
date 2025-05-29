#include <iostream>

#include "Auxilary/Auxilaries.h"
#include "Auxilary/ScriptNamePrinter.h"
#include "Problems/GeeksForGeeksTravellingSalesmanProblem.h"
#include "Problems/LeetCode3372MaximizeTheNumberOfTargetNodesAfterConnectingTreesI.h"
#include "Problems/LeetCode3373MaximizeTheNumberOfTargetNodesAfterConnectingTreesII.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const auto problem = new LeetCode3373MaximizeTheNumberOfTargetNodesAfterConnectingTreesII();
    problem->Run();
    delete problem;


#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "3373. Maximize the Number of Target Nodes After Connecting Trees II";
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
