#pragma once
#include <complex>
#include <vector>

class LeetCode1534CountGoodTriplets
{
public:
    int countGoodTriplets(std::vector<int>& arr, int a, int b, int c) {
        int length=static_cast<int>(arr.size());
        int result{};
        int deltaIJ{};
        int deltaJK{};
        int deltaIK{};
        for (int i=0;i<length-2;i++)
        {
            for (int j=i+1;j<length-1;j++)
            {
                deltaIJ = std::abs(arr[i] - arr[j]);
                if (deltaIJ>a)
                    continue;
                for (int k=j+1;k<length;k++)
                {
                    deltaJK = std::abs(arr[j] - arr[k]);
                    deltaIK = std::abs(arr[i] - arr[k]);
                    if (deltaJK>b)
                        continue;
                    if (deltaIK>c)
                        continue;
                    result++;
                }
            }
        }
        return result;
    }
};
