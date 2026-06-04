//
// Created by saeed on 6/4/26.
//

#include "LeetCode3751TotalWavinessOfNumbersInRangeI.h"
int getWaviness(int num) {
    int previous=num%10;
    num=num/10;
    int result{},next{},current{};
    while (num>0) {
        current=num%10;
        num/=10;
        if (num==0)
            break;
        next=num%10;
        if ((current>previous && current>next) || (current<previous && current<next))
            result++;
        previous=current;
    }
    return result;

}
int LeetCode3751TotalWavinessOfNumbersInRangeI::totalWaviness(int num1, int num2) {
    int result{};
    for (;num1<=num2;++num1) {
        result+=getWaviness(num1);
    }
    return result;
}
