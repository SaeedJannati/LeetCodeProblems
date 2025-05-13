//
// Created by saeed on 5/13/25.
//

#include "LeetCode3335TotalCharactersInStringAfterTransformationsI.h"

#include <unordered_map>
#include <vector>
using namespace  std;
int LeetCode3335TotalCharactersInStringAfterTransformationsI::lengthAfterTransformations(string s, int t) {
    vector<long long> frequencies(26,0);
    for(int i = 0; i<s.length(); i++) {
        frequencies[s[i]-'a']++;
    }
    long long temp = 0;
    long long temp2 = 0;
    long long modulo=1'000'000'007;
    for(int i = 0; i<t; i++) {
        temp=0;
        temp2=0;
        for(int j = 0; j<25; j++) {
            temp=frequencies[j];
            frequencies[j] = temp2;
            temp2 = temp;
        }
        frequencies[0]+=frequencies[25]%modulo;
        frequencies[0]%=modulo;
        frequencies[1]+=frequencies[25]%modulo;
        frequencies[1]%=modulo;
        frequencies[25]=temp;
    }
    long long result = 0;
    for(int i = 0; i<26; i++) {
        result+= (frequencies[i]%modulo);
        result %= modulo;
    }
    return result;
}
