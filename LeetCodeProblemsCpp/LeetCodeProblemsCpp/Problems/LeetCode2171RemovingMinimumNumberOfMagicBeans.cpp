#include "LeetCode2171RemovingMinimumNumberOfMagicBeans.h"

#include <algorithm>
#include <numeric>
using  namespace std;
long long LeetCode2171RemovingMinimumNumberOfMagicBeans::minimumRemoval( vector<int>& beans)
{
    ranges::sort(beans);
  
    long long totalCount=accumulate(beans.begin(),beans.end(),0LL);
    int length = static_cast<int>( beans.size());
    long long result= numeric_limits<long long>::max();
    
    for (int i=0;i<length;i++)
    {
      result=min(result,totalCount- static_cast<long long>(length-i)*static_cast<long long>(beans[i]));
      
    }
    return result;
}
