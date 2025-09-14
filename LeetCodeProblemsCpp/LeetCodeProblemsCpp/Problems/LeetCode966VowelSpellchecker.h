#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "Auxilaries.h"
#include "BaseProblem.h"
using namespace std;

class LeetCode966VowelSpellchecker : BaseProblem
{
public:


    bool isVowel(char c)
    {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }

  

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries)
    {
        unordered_set<string> caseSensitiveMap{};
        unordered_map<string,string> omitCapitalMap{};
        unordered_map<string,string> omitVowelMap{};
        for (auto word : wordlist)
        {
            caseSensitiveMap.insert(word);
            auto lowerWord = word;
            for (auto &c: lowerWord)
                c = tolower(c);
            if (!omitCapitalMap.contains(lowerWord))
            {
                omitCapitalMap[lowerWord]= word;
            }
            auto omitVowelWord = lowerWord;
            for (auto &c: omitVowelWord)
            {
                if (isVowel(c))
                {
                    c='.';
                }
            }
            if (!omitVowelMap.contains(omitVowelWord))
            {
                omitVowelMap[omitVowelWord]= word;
            }
        }
        vector<string> result{};
        result.reserve(queries.size());
        for (auto query : queries)
        {
         if (caseSensitiveMap.contains(query))
         {
             result.push_back(query);
             continue;
         }
            auto lowerWord = query;
            for (auto &c: lowerWord)
                c = tolower(c);
            if (omitCapitalMap.contains(lowerWord))
            {
                result.push_back(omitCapitalMap[lowerWord]);
                continue;
            }
            auto omitVowelWord = lowerWord;
            for (auto &c: omitVowelWord)
            {
                if (isVowel(c))
                    c='.';
            }
            if (omitVowelMap.contains(omitVowelWord))
            {
                result.push_back(omitVowelMap[omitVowelWord]);
                continue;
            }
            result.push_back("");
        }
        return result;
    }

    void Run() override
    {
        vector<string> wordList{"KiTe", "kite", "hare", "Hare"};
        vector<string> queries{"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"};
        auto result=spellchecker(wordList, queries);
        
    }
};
