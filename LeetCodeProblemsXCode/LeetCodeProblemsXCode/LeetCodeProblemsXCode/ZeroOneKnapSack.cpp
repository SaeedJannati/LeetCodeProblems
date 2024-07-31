//
//  ZeroOneKnapSack.cpp
//  LeetCodeProblemsXCode
//
//  Created by Saeed Jannati on 5/10/1403 AP.
//

#include "ZeroOneKnapSack.hpp"
void ZeroOneKnapSack::Run()
{
    int n=3;
    int val[]={1,2,3};
    int wt[]={4,5,1};
    int w=4;
    auto outPut=knapSack(w, wt, val, n);
    std::cout<<outPut<<'\n';
}


int ZeroOneKnapSack::knapSack(int w, int wt[], int val[], int n)
{
    int** dp=new int*[n+1];
    for (int i=0; i<n+1; i++)
    {
        dp[i]=new int[w+1];
    }
    
    for (int j=0; j<w+1; j++) {
        for (int i=0; i<n+1; i++) {
            if(j==0 || i==0)
            {
                dp[i][j]=0;
                continue;
            }
            if(j-wt[i-1]<0)
            {
                dp[i][j]=dp[i-1][j];
                continue;
            }
            dp[i][j]=std::max(dp[i-1][j] , val[i-1]+dp[i-1][j-wt[i-1]]);
        }
    }
    int value=dp[n][w];
    for (int i=0; i<n; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return value;
}
