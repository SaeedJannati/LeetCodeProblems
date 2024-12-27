#include "LeetCode70ClimbingStairs.h"

#include <vector>

void LeetCode70ClimbingStairs::Run()
{
    BaseProblem::Run();
}

int LeetCode70ClimbingStairs::climbStairs(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    std::vector<int> dpMatrix(n);
    dpMatrix.reserve(n);
    dpMatrix[0] = 1;
    dpMatrix[1]=2;
    for (int i=2;i<n;i++)
    {
        dpMatrix[i]=dpMatrix[i-1]+dpMatrix[i-2];
    }
    return dpMatrix[n-1];
    
}
