#include "LeetCode2125NumberOfLaserBeamsInABank.h"

int LeetCode2125NumberOfLaserBeamsInABank::numberOfBeams(std::vector<std::string>& bank)
{
    int beamCount{};
    int previousRowDeviceCount{};
    int currentRowDeviceCount{};
    for (auto & row : bank)
    {
        currentRowDeviceCount=0;
        for (auto c:row)
        {
            if (c=='1')
            {
                ++currentRowDeviceCount;
            }
        }
        if (currentRowDeviceCount==0)
            continue;
        beamCount+=currentRowDeviceCount*previousRowDeviceCount;
        previousRowDeviceCount=currentRowDeviceCount;
    }
    return beamCount;
}
