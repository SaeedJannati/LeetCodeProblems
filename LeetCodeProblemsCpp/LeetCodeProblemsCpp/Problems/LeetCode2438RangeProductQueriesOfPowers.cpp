#include "LeetCode2438RangeProductQueriesOfPowers.h"

#include "Auxilaries.h"
using namespace std;
int moduloPow(int power,int modulo)
{
    long result=1;
    int currentPower=1;
    long current{2};
    while (currentPower<=power)
    {
        if (currentPower&power)
        {
            result=(result*current)%modulo;
        }
        current*=current;
        current%=modulo;
        currentPower <<=1;
    }
    return static_cast<int>(result);
}
vector<int> LeetCode2438RangeProductQueriesOfPowers::productQueries(int n, vector<vector<int>>& queries)
{
    const long modulo=1e9+7;
    vector<int> powOfTwos{};
    long powOfTwo{1};
    int power{};
    while (powOfTwo<=n)
    {
        if ((n&powOfTwo)==powOfTwo)
        {
            powOfTwos.push_back(power);
        }
        if (powOfTwo>=n)
            break;
        powOfTwo <<=1;
        power++;
    }
    int powTwoLength=static_cast<int>(powOfTwos.size());
    for (int i=1;i<powTwoLength;i++)
    {
        powOfTwos[i]+=powOfTwos[i-1];
    }
    int length=static_cast<int>(queries.size());
    vector<int> result(length,0);
    for (int i=0;i<length;i++)
    {
        int lowerBound=queries[i][0]>0?powOfTwos[ queries[i][0]-1] : 0;
        int pow= powOfTwos[ queries[i][1]]-lowerBound;
        result[i]=moduloPow(pow,modulo);
    }
    return result;
}

void LeetCode2438RangeProductQueriesOfPowers::Run()
{
    vector<vector<int>> queries{{0,1},{2,2},{0,3}};
    int n{15};
    Auxilaries::PrintVector(productQueries(n,queries));
}
