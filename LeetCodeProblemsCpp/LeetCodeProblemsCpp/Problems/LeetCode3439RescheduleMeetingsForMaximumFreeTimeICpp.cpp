#include "LeetCode3439RescheduleMeetingsForMaximumFreeTimeICpp.h"
using namespace std;
int LeetCode3439RescheduleMeetingsForMaximumFreeTimeICpp::maxFreeTime(int eventTime, int k,  vector<int>& startTime,  vector<int>& endTime)
{
    int length=startTime.size();
    vector<int> delays(length+1);
    int lastEndTime{};
    for (int i=0;i<length;i++)
    {
        delays[i]=startTime[i]-lastEndTime;
        lastEndTime=endTime[i];
    }
    delays[length]=eventTime-lastEndTime;
    int maxDelay{};
    int currentDelay{};
    for (int i=0;i<=k;i++)
    {
        currentDelay+= delays[i];
    }
    maxDelay=currentDelay;
    for (int i=k+1;i<=length;i++)
    {
        currentDelay+=delays[i];
        currentDelay-=delays[i-k-1];
        maxDelay=max(maxDelay,currentDelay);
    }
    return maxDelay;
}
