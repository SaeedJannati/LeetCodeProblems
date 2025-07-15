#include "LeetCode3136ValidWord.h"
using namespace std;
bool isLetter(char c)
{
    if (c>='A' && c<='Z')
        return true;
    if (c>='a' && c<='z')
        return true;
    return false;
}
bool isValidChar(char c)
{
    if (c>='0' && c<='9')
        return true;
    if (isLetter(c))
        return true;
    return false;
}
bool isVowel(char c)
{
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        return true;
    if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        return true;
    return false;
}
bool isConsonant(char c)
{
    if (isVowel(c))
        return false;
    if (isLetter(c))
        return true;
    return false;
}
bool LeetCode3136ValidWord::isValid(string word)
{
    int length = word.length();
    if (length<3)
        return false;
    int vowelCount{};
    int consonantCount{};
    for (auto c:word)
    {
        if (!isValidChar(c))
            return false;
        if (isConsonant(c))
            consonantCount++;
        if (isVowel(c))
            vowelCount++;
    }
    return vowelCount>0&&consonantCount>0;
}




