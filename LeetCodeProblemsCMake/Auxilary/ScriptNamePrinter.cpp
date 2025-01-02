//
// Created by saeed on 1/2/25.
//

#include "ScriptNamePrinter.h"

#include <iostream>

void ScriptNamePrinter::PrintScriptName(const std::string &scriptName) {
    std::string name = ConvertScriptName(scriptName);
    std::string commitName = "feat: add " + name;

    std::cout << name << std::endl;
    std::cout << commitName << std::endl;
}

std::string ScriptNamePrinter::ConvertScriptName(const std::string &input) {
    std::string result;
    result.reserve(input.size());

    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] == ' ' && i + 1 < input.size()) {
            result += std::toupper(input[i + 1]);
            ++i; // Skip the next character as it's already added
        } else if (input[i] != ' ' && input[i] != '-' && input[i] != '.' &&
                   input[i] != '(' && input[i] != ')' && input[i] != '[' &&
                   input[i] != ']' && input[i] != '{' && input[i] != '}' &&
                   input[i] != '\'') {
            result += input[i];
                   }
    }

    result = "LeetCode" + result;
    return result;
}
