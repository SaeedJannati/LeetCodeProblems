#include "LeetCode11ContainerWithMostWater.h"

#include <iostream>
#include <string>

void LeetCode11ContainerWithMostWater::Run()
{
    std::vector<int> heights{1,8,6,2,5,4,8,3,7};
    const auto area = maxArea(heights);
    std::cout << std::to_string(area) << '\n';
}

int LeetCode11ContainerWithMostWater::maxArea(std::vector<int>& height)
{
    int size = static_cast<int>(height.size());
    if (size == 0 || size == 1)
        return 0;
    int firstPointer(0);
    int secondPointer(size - 1);
    int maxArea(0);
    int currentArea(0);
    bool isFirstGreater(false);
    while (firstPointer != secondPointer)
    {
        isFirstGreater=height[firstPointer]>height[secondPointer];
        currentArea=(secondPointer-firstPointer)*(isFirstGreater?height[secondPointer]:height[firstPointer]);
        if(currentArea>maxArea)
            maxArea=currentArea;
        if(!isFirstGreater)
        {
            firstPointer++;
            continue;
        }
        secondPointer--;   
    }
    return maxArea;
}
