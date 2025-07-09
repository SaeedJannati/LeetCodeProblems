//
// Created by saeed on 6/10/25.
//

#include "LeetCode3442MaximumDifferenceBetweenEvenAndOddFrequencyI.h"

#include <vector>
using namespace std;
int LeetCode3442MaximumDifferenceBetweenEvenAndOddFrequencyI::maxDifference(string s) {
    vector<char> frequencies(26,0);
    for (auto c : s) {
        frequencies[c-'a']++;
    }
    char maxOdd{0};
    char minEven{101};
    for (auto f : frequencies) {
        if (f%2==1) {
            if (f>maxOdd) {
                maxOdd = f;
            }
            continue;
        }
        if (f==0)
            continue;
        if (f<minEven) {
            minEven = f;
        }
    }

    return maxOdd - minEven;
}
