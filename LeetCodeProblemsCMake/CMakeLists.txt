cmake_minimum_required(VERSION 3.30)
project(LeetCodeProblemsCMake)

set(CMAKE_CXX_STANDARD 20)

add_executable(LeetCodeProblemsCMake main.cpp
        Auxilary/TreeNode.cpp
        Auxilary/TreeNode.h
        Auxilary/Auxilaries.cpp
        Auxilary/Auxilaries.h
        Problems/BaseProblem.cpp
        Problems/BaseProblem.h
        Auxilary/ScriptNamePrinter.cpp
        Auxilary/ScriptNamePrinter.h
        Problems/LeetCode2559CountVowelStringsInRanges.cpp
        Problems/LeetCode2559CountVowelStringsInRanges.h
        Problems/LeetCode2138DivideAStringIntoGroupsOfSizeK.cpp
        Problems/LeetCode2138DivideAStringIntoGroupsOfSizeK.h
        Problems/LeetCode40CombinationSumII.cpp
        Problems/LeetCode40CombinationSumII.h
        Problems/LeetCode2270NumberOfWaysToSplitArray.cpp
        Problems/LeetCode2270NumberOfWaysToSplitArray.h
        Problems/LeetCode184Sum.cpp
        Problems/LeetCode184Sum.h
        Problems/LeetCode47PermutationsII.cpp
        Problems/LeetCode47PermutationsII.h
        Problems/LeetCode1930UniqueLength3PalindromicSubsequences.cpp
        Problems/LeetCode1930UniqueLength3PalindromicSubsequences.h
)
