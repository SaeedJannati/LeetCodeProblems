#include "LeetCode231PowerOfTwo.h"

#include <iostream>
bool LeetCode231PowerOfTwo::isPowerOfTwo(int n)
{
    if (n <= 0)
    {
        return false;
    }
   return (n&(n-1))==0;
}
#pragma region with loop
// bool LeetCode231PowerOfTwo::isPowerOfTwo(int n)
// {
//     if (n < 0)
//     {
//         return false;
//     }
//     int powOfTwo = 1;
//     bool hasPowOfTwo = false;
//     while (powOfTwo <= n)
//     {
//         if ((n & powOfTwo) == powOfTwo)
//         {
//             if (hasPowOfTwo)
//             {
//                 return false;
//             }
//             hasPowOfTwo = true;
//         }
//         if (powOfTwo == 1 << 31)
//         {
//             break;
//         }
//         powOfTwo <<= 1;
//     }
//     return hasPowOfTwo;
// }
#pragma endregion 
void LeetCode231PowerOfTwo::Run()
{
    int n = 1073741824;
    std::cout << isPowerOfTwo(n) << '\n';
}
