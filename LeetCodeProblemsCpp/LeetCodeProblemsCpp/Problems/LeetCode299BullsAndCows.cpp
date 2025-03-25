#include "LeetCode299BullsAndCows.h"

#include <unordered_map>
using namespace std;

string LeetCode299BullsAndCows::getHint(string secret, string guess)
{
    unordered_map<char,int> secretMap{};
    unordered_map<char,int> guessMap{};
    int bulls{};
    int length=secret.length();
    for (int i=0;i<length;i++)
    {
        if (secret[i]==guess[i])
        {
            bulls++;
            continue;
        }
        if (!guessMap.contains(guess[i]))
            guessMap[guess[i]]=0;
        if (!secretMap.contains(secret[i]))
            secretMap[secret[i]]=0;
        secretMap[secret[i]]++;
        guessMap[guess[i]]++;
    }
    int cows{};
    for (auto & pair:secretMap)
    {
        if (!guessMap.contains(pair.first))
            continue;
        cows+=min(pair.second,guessMap[pair.first]);
    }
    return to_string(bulls)+"A"+to_string(cows)+"B";
}
