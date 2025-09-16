#include "LeetCode2197ReplaceNonCoprimeNumbersInArray.h"

#include <algorithm>
#include <stack>

#include "Auxilaries.h"
using namespace std;
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
int LCM(int a,int b)
{
    long result=a;
    result*=b;
    result/=GCD(a,b);
    return result;
}
vector<int> LeetCode2197ReplaceNonCoprimeNumbersInArray::replaceNonCoprimes(vector<int>& nums)
{
    stack<int> numsStack{};
    numsStack.push(nums[0]);
    for(int i=1,e= static_cast<int>(nums.size());i<e;i++)
    {
        auto num = nums[i];
        auto top = numsStack.top();
        while (GCD(top,num)>1 )
        {
            num=LCM(top,num);
            numsStack.pop();
            if (numsStack.empty())
                break;
            top = numsStack.top();
        }
        numsStack.push(num);
    }
    vector<int> result{};
    result.reserve(numsStack.size());
    while (!numsStack.empty() )
    {
        result.push_back(numsStack.top());
        numsStack.pop();
    }
    ranges::reverse(result);
    return result;
}

void LeetCode2197ReplaceNonCoprimeNumbersInArray::Run()
{
    vector<int> nums{6,4,3,2,7,6,2};
    Auxilaries::PrintVector(replaceNonCoprimes(nums));
}
