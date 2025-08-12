#include "LeetCode2787WaysToExpressAnIntegerAsSumOfPowers.h"

#include <algorithm>
#include <iostream>
#include <valarray>
#include <vector>
#include <__msvc_ostream.hpp>
using namespace std;
#pragma  region 1D dp
int LeetCode2787WaysToExpressAnIntegerAsSumOfPowers::numberOfWays(int n, int x)
{
    const int modulo =1e9+7;
    long num{};
    int being{1};
    int end{n};
    int mid{};
    int maxNum{-1};
    while (being <= end)
    {
        mid = (being + end) >> 1;
        num = pow(mid, x);
        if (num <= n)
        {
            maxNum = max(maxNum, mid);
            being = mid + 1;
            continue;
        }
        end = mid - 1;
    }
    if (maxNum == -1)
        return 0;
    vector<int> nums(maxNum+1,0);
    for (int i = 1; i <= maxNum; ++i)
    {
        nums[i]=pow(i, x);
    }
    vector<long> last( vector<long>(n + 1, 0));
    last[0] = 1;
    vector<long> current( vector<long>(n + 1, 0));
  
    for (int i=1;i<=maxNum;i++)
    {
        for (int j=0;j<=n;j++)
        {
            if (j - nums[i] >= 0)
            {
                current[j] = last[j] + last[j - nums[i]];
                current[j]%=modulo;
            }
            else
            {
                current[j] = last[j];
            }
        }
        last.swap(current) ;
        std::ranges::fill(current, 0);
    }
    return last[n];
}
#pragma  endregion 
#pragma region 2D dp
// int LeetCode2787WaysToExpressAnIntegerAsSumOfPowers::numberOfWays(int n, int x)
// {
//     const int modulo =1e9+7;
//     long num{};
//     int being{1};
//     int end{n};
//     int mid{};
//     int maxNum{-1};
//     while (being <= end)
//     {
//         mid = (being + end) >> 1;
//         num = pow(mid, x);
//         if (num <= n)
//         {
//             maxNum = max(maxNum, mid);
//             being = mid + 1;
//             continue;
//         }
//         end = mid - 1;
//     }
//     if (maxNum == -1)
//         return 0;
//     vector<int> nums(maxNum+1,0);
//     for (int i = 1; i <= maxNum; ++i)
//     {
//         nums[i]=pow(i, x);
//     }
//     vector<vector<long>> dp(maxNum + 1, vector<long>(n + 1, 0));
//     for (int i = 0; i <= maxNum; ++i)
//     {
//         dp[i][0] = 1; 
//     }
//     for (int i=1;i<=maxNum;i++)
//     {
//         for (int j=1;j<=n;j++)
//         {
//             if (j - nums[i] >= 0)
//             {
//                 dp[i][j] = dp[i - 1][j] + dp[i-1][j - nums[i]];
//                 dp[i][j]%=modulo;
//             }
//             else
//             {
//                 dp[i][j] = dp[i - 1][j];
//                 dp[i][j]%=modulo;
//             }
//         }
//     }
//   return dp[maxNum][n];
// }
#pragma endregion 
void LeetCode2787WaysToExpressAnIntegerAsSumOfPowers::Run()
{
    int n = 4;
    int x = 1;
    cout << numberOfWays(n, x) << endl;
}
