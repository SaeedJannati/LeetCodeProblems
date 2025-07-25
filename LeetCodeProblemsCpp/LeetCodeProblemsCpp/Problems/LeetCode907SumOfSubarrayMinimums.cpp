#include "LeetCode907SumOfSubarrayMinimums.h"

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int LeetCode907SumOfSubarrayMinimums::sumSubarrayMins(vector<int>& arr)
{
    int modulo=1e9+7;
    stack<pair<int, int>> monotonicStack{};
    int length=arr.size();
    vector<int> leftFirstLesserIndex(length,-1);
    vector<int> rightFirstLesserIndex(length,length);
    monotonicStack.emplace(arr[0],0);
    pair<int,int> top{};
    for(int i=1;i<length;i++)
    {
        while ((!monotonicStack.empty()) && monotonicStack.top().first>=arr[i])
        {
            monotonicStack.pop();
        }
        if (monotonicStack.empty())
        {
            monotonicStack.emplace(arr[i],i);
            leftFirstLesserIndex[i]=-1;
            continue;
        }
        leftFirstLesserIndex[i]=monotonicStack.top().second;
        monotonicStack.emplace(arr[i],i);
    }
    monotonicStack={};
    monotonicStack.emplace(arr[length-1],length-1);
    for (int i=length-2;i>=0;i--)
    {
        while ((!monotonicStack.empty())&&monotonicStack.top().first> arr[i])
        {
            monotonicStack.pop();
        }
        if (monotonicStack.empty())
        {
            monotonicStack.emplace(arr[i],i);
            rightFirstLesserIndex[i]=length;
            continue;
        }
        rightFirstLesserIndex[i]=monotonicStack.top().second;
        monotonicStack.emplace(arr[i],i);
    }
    long long result{};
    long long delta{};
    for (int i=0;i<length;i++)
    {
        delta=arr[i];
        delta*= i-(leftFirstLesserIndex[i]+1)+1;
        delta%=modulo;
        delta*=rightFirstLesserIndex[i]-i;
        delta%=modulo;
        result+=delta;
        result%=modulo;
    }
    return result;
}

void LeetCode907SumOfSubarrayMinimums::Run()
{
    vector<int> arr={71,55,82,55};
        // {3,1,2,4};
    cout<<sumSubarrayMins(arr)<<endl;
}
