#include "LeetCode135Candy.h"

#include <iostream>
#include <ostream>

void LeetCode135Candy::Run()
{
    std::vector<int> input = {1,0,2};
    auto output = candy(input);
    std::cout << "candy:" << output << '\n';
}

int LeetCode135Candy::candy(std::vector<int>& ratings)
{
    int size = static_cast<int>(ratings.size());
    if (size == 0)
        return 0;
    if (size == 1)
        return 1;
    int candyCount = size;
    int upStreak{0};
    int downStreak{0};
    for (int i = 1; i < size; i++)
    {
        if (i == size - 1)
        {
            if (ratings[size - 1] > ratings[size - 2])
            {
                upStreak++;
                candyCount+=upStreak;
            }
              
            if(ratings[size-1]<ratings[size-2] )
            {
                downStreak++;
                if( upStreak==0)
                {
                    candyCount+=downStreak;
                }
                else
                {
                    if(downStreak>upStreak)
                        candyCount+=downStreak;
                    else
                    {
                        candyCount+=downStreak-1;
                    }
                }
            }
            continue;
        }

        if (ratings[i] > ratings[i - 1])
        {
            if(downStreak>0)
            {
                downStreak=0;
                upStreak=0;
            }
            upStreak++;
            candyCount+=upStreak;
            continue;
        }
        if(ratings[i]<ratings[i - 1])
        {
            downStreak++;
            if( upStreak==0)
            {
                candyCount+=downStreak;
            }
            else
            {
                if(downStreak>upStreak)
                    candyCount+=downStreak;
                else
                {
                    candyCount+=downStreak-1;
                }
            }
            if(ratings[i]<=ratings[i + 1])
            {
                upStreak=0;
                continue;
            }
        }
        if(ratings[i]==ratings[i - 1])
        {
            upStreak=0;
            downStreak=0;
        }
    }
    return candyCount;
}



