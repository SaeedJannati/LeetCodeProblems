#include "LeetCode2381ShiftingLettersII.h"

#include <iostream>
#include <ostream>

std::string LeetCode2381ShiftingLettersII::shiftingLetters(std::string s, std::vector<std::vector<int>>& shifts)
{
    int sLength = static_cast<int>(s.length());
    int shiftsLength = static_cast<int>(shifts.size());
    std::vector<int> shiftedLetters(sLength, 0);
    int start;
    int end;
    int direction;
    for (int i = 0; i < shiftsLength; i++)
    {
        start = shifts[i][0];
        end = shifts[i][1];
        direction = shifts[i][2] == 0 ? -1 : 1;
        shiftedLetters[start] += direction;
        if (end == sLength - 1)
            continue;
        shiftedLetters[end+1] -= direction;
    }
    for (int i = 1; i < sLength; i++)
    {
        shiftedLetters[i] += shiftedLetters[i - 1];
    }
    int letter;
    for (int i = 0; i < sLength; i++)
    {
        letter = s[i];
        letter += shiftedLetters[i];
        if (letter > 'z' || letter < 'a')
        {
            letter = (letter - 'a') % 26;
            if (letter < 0)
                letter += 26;
            letter += 'a';
        }
        s[i] = letter;
    }
    return s;
}

void LeetCode2381ShiftingLettersII::Run()
{
    std::string s = "ksztajnymer";
    std::vector<std::vector<int>> shifts = {
        {4, 9, 1}, {2, 5, 1}, {7, 9, 0}, {6, 10, 0}, {1, 7, 1}, {0, 7, 1}, {0, 3, 0}, {3, 3, 1}, {7, 9, 0}, {7, 7, 0},
        {6, 7, 0}, {7, 9, 0}, {3, 9, 0}, {10, 10, 1}, {8, 9, 0}, {6, 9, 1}, {1, 2, 1}, {3, 9, 0}, {8, 10, 1}, {4, 7, 1},
        {9, 10, 1}, {8, 9, 0}, {5, 8, 0}, {8, 9, 1}, {0, 7, 1}, {2, 2, 1}, {8, 8, 1}, {3, 7, 0}, {1, 10, 1}, {9, 9, 1},
        {4, 9, 0}, {5, 6, 1}, {7, 8, 1}, {8, 9, 0}, {7, 7, 1}, {9, 9, 1}
    };
    std::cout << shiftingLetters(s, shifts) << '\n';
}
