//
// Created by saeed on 1/29/25.
//

#include "GeeksForGeeksAlienDictionary.h"

#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>

bool Dfs(std::vector<int> &visited, std::unordered_map<char, std::unordered_set<char> > &adjPlus,
         std::stack<char> &stack, char node) {
    if (visited[node - 'a'] == 2)
        return true;
    if (visited[node - 'a'] == 1)
        return false;
    visited[node - 'a'] = 1;
    if (adjPlus[node].empty()) {
        stack.push(node);
        visited[node - 'a'] = 2;
        return true;
    }
    for (auto &c: adjPlus[node]) {
        if (!Dfs(visited, adjPlus, stack, c))
            return false;
    }
    stack.push(node);
    visited[node - 'a'] = 2;
    return true;
}

void FindEdges(std::vector<std::string> &words, std::unordered_map<char, std::unordered_set<char> > &adjPlus,
               int index) {
    char previousChar{};
    std::vector<std::vector<std::string> > wordsList{};
    previousChar = 0;
    std::vector<std::string> currentWords{};
    for (int i=0,e=words.size(); i <e; i++) {
        if (index >= words[i].size())
            continue;
        if (previousChar == 0) {
            previousChar = words[i][index];
            continue;
        }
        if (previousChar != words[i][index]) {
            if (currentWords.size()>1) {
                std::vector<std::string> newWords=currentWords;
                wordsList.push_back(newWords);
            }
            currentWords={words[i]};
            if (adjPlus.find(previousChar)==adjPlus.end())
                adjPlus[previousChar] = std::unordered_set<char>();
            if (adjPlus[previousChar].find(words[i][index])==adjPlus[previousChar].end())
                adjPlus[previousChar].insert(words[i][index]);
        }
        else {
            if (currentWords.empty())
                currentWords.push_back(words[i-1]);
            currentWords.push_back(words[i]);
        }
        previousChar = words[i][index];
    }
    if (currentWords.size()>1) {
        wordsList.push_back(currentWords);
    }
    for (auto &wordSet: wordsList) {
        FindEdges(wordSet, adjPlus, index+1);
    }
}

std::string GeeksForGeeksAlienDictionary::findOrder(std::vector<std::string> dict, int k) {
    std::string order = "";
    std::unordered_map<char, std::unordered_set<char> > adjPlus{};
    FindEdges(dict, adjPlus, 0);
    std::vector<int> visited(k, 0);
    std::stack<char> stack{};
    for (int i = 0; i < k; i++) {
        if (!Dfs(visited, adjPlus, stack, 'a'+i))
            return "";
    }

    while (!stack.empty()) {
        order += stack.top();
        stack.pop();
    }
    return order;
}

void GeeksForGeeksAlienDictionary::Run() {


    std::vector<std::string> dict =
        // {"dhhid","dahi","cedg","fg","gdah","i","gbdei","hbgf","e","ddde"};
        // {"caa","aaa","aab"};
        {"baa", "abcd", "abca", "cab", "cad"};
    int k = 4;
    std::cout << findOrder(dict, k);
}





