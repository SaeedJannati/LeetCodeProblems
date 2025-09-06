#include "LeetCode3495MinimumOperationsToMakeArrayElementsZero.h"

#include <iostream>
#include <queue>
using namespace std;

int getLeftMostBit(int n)
{
    if (n == 0)
        return 0;
    int bit{0};
    while (n)
    {
        n >>= 1;
        bit++;
    }
    return bit - 1;
}

long long LeetCode3495MinimumOperationsToMakeArrayElementsZero::minOperations(vector<vector<int>>& queries)
{
    long long result{};
  
    for (auto& query : queries)
    {
        vector<int> powOfTwos(32,0);
        int leftLargest = getLeftMostBit(query[0]);
        int rightLargest = getLeftMostBit(query[1]);
        int lastNum = query[0];
        int delta{};
        for (int i = leftLargest + 1; i <= rightLargest; i++)
        {
            delta = (1 << i) - lastNum;
            powOfTwos[i-1]=delta;
            lastNum = (1 << i);
        }
        delta = query[1] - lastNum + 1;
        powOfTwos[rightLargest]= delta;
        for (int i=31;i>=0;i--)
        {
            if (powOfTwos[i] == 0)
                continue;
            int pairs = powOfTwos[i] / 2;
            result +=   pairs;
            if (i>1)
            {
                powOfTwos[i-2]+=(pairs*2);
            }
            
            if (powOfTwos[i] % 2 == 1)
            {
                bool solved{};
                for (int j=i-1;j>=0;j--)
                {
                    if (powOfTwos[j] == 0)
                        continue;
                    result++;
                    powOfTwos[j] --;
                    if (i>1)
                    {
                        powOfTwos[i-2]++;
                    }
                    if (j>1)
                    {
                        powOfTwos[j-2]++;
                    }
                    solved=true;
                    break;
                }
                if (!solved)
                {
                    result+=i/2+1;
                }
            }
        }
    }
    return result;
}

void LeetCode3495MinimumOperationsToMakeArrayElementsZero::Run()
{
    vector<vector<int>> queries ={{5,9}};
        // {{1,2},{2,4}};
        // {{2, 6}};
    cout << minOperations(queries);
}
