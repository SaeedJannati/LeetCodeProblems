#include "LeetCode88MergeSortedArray.h"

#include <iostream>

void LeetCode88MergeSortedArray::Run()
{
    std::vector<int> nums1={1,2,3,0,0,0};
    int m=3;
    std::vector<int> nums2={2,5,6};
    int n=3;
    merge(nums1,m,nums2,n);
    PrintVector(nums1);
}

void LeetCode88MergeSortedArray::merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    if(m==0)
        nums1=nums2;
    if(n==0)
        return;
    std::vector<int> temp;
    temp.reserve(m+n);
    int firstPointer=0;
    int secondPointer=0;
    int valueToInsert=0;
    for (int i=0,e=m+n; i<e; i++)
    {
        if(firstPointer<m && secondPointer<n)
        {
            if(nums1[firstPointer]<=nums2[secondPointer])
            {
                temp.push_back(nums1[firstPointer]);
                firstPointer++;
                continue;
            }
            temp.push_back(nums2[secondPointer]);
            secondPointer++;
        }
        else
        {
            if(firstPointer<m)
            {
                temp.push_back(nums1[firstPointer]);
                firstPointer++;
                continue;
            }
            temp.push_back(nums2[secondPointer]);
            secondPointer++;
        }
    }
    nums1 = temp;
}
void LeetCode88MergeSortedArray::PrintVector(std::vector<int>& vector)
{
    for (const auto i : vector)
        std::cout << i << " ";
    std::cout << '\n';
}
