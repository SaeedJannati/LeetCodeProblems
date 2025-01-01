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
        Problems/SampleProblem.cpp
        Problems/SampleProblem.h)
