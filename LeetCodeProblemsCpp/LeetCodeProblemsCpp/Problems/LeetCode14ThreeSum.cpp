#include "LeetCode14ThreeSum.h"

#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>


void LeetCode14ThreeSum::Run()
{
    std::vector<int> input = {0,1,1};

    auto result = threeSum(input);
    PrintTwoDimensionalArray(result);
}

std::vector<std::vector<int>> LeetCode14ThreeSum::threeSum(std::vector<int>& nums)
{
    std::unordered_map<std::string,std::vector<int>> tripletsSet;
    std::vector<std::vector<int>> outPut;
    std::unordered_map<int, int> keyOccurrenceMap;
    
    int size = static_cast<int>(nums.size());
    for (int i=0;i<size;i++)
    {
        if (keyOccurrenceMap.count(nums[i]) > 0)
            keyOccurrenceMap[nums[i]]++;
        else
            keyOccurrenceMap[nums[i]] = 1;
    }
    int occurrenceCount;
    int targetValue;
    std::string tripletString;
    for (int i = 0; i < size; i++)
    {
        for (int j=i+1;j<size;j++)
        {
            if(i==j)
                continue;
            targetValue=-(nums[i]+nums[j]);
            occurrenceCount=keyOccurrenceMap[targetValue];
            if(occurrenceCount==0)
                continue;
            if(occurrenceCount==1)
            {
                if(targetValue==nums[i]||targetValue==nums[j])
                    continue;
            }
            if(occurrenceCount==2)
            {
                if(nums[i]==0&&nums[j]==0)
                    continue;
            }
            std::vector<int> vector={nums[i],nums[j],targetValue};
            SortVector(vector);
            tripletString=std::to_string(vector[0])+','+std::to_string(vector[1])+','+std::to_string(vector[2]);
            if(tripletsSet.count(tripletString)>0)
                continue;
            tripletsSet[tripletString]=vector;
        }
    }
   for (auto& triplet:tripletsSet)
   {
       outPut.push_back(triplet.second);
   }
    return outPut;
}
void LeetCode14ThreeSum::SortVector(std::vector<int>& vector)
{
    if(vector[2]<vector[1])
        std::swap(vector[2],vector[1]);
    if(vector[1]<vector[0])
        std::swap(vector[1],vector[0]);
    if(vector[2]<vector[1])
        std::swap(vector[2],vector[1]);
}
void LeetCode14ThreeSum::PrintTwoDimensionalArray(std::vector<std::vector<int>>& input)
{
    std::ostringstream outPut;
    outPut << "{";
    for (auto& i : input)
    {
        outPut << "[";
        for (const int j : i)
        {
            outPut << std::to_string(j) << ",";
        }
        outPut << "],";
    }
    outPut << "}";
    std::cout << outPut.str();
}
