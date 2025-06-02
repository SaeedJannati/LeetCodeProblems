//
// Created by saeed on 6/2/25.
//

#include "LeetCode187RepeatedDNASequences.h"

#include <unordered_map>
#include <unordered_set>

#include "../Auxilary/Auxilaries.h"
using namespace std;

vector<string> LeetCode187RepeatedDNASequences::findRepeatedDnaSequences(string s) {
    vector<string> result{};
    int length = static_cast<int>(s.length());
    if (length < 11)
        return result;
    int currentSequence{};
    int numToAdd{};
    const int clearMask = (1 << 20) - 1;
    for (int i = 0; i < 10; i++) {
        currentSequence <<= 2;
        switch (s[i]) {
            case 'A':
                numToAdd = 0;
                break;
            case 'C':
                numToAdd = 1;
                break;
            case 'G':
                numToAdd = 2;
                break;
            case 'T':
                numToAdd = 3;
                break;
        }
        currentSequence |= numToAdd;
    }
    unordered_set<int> resultNums{};
    unordered_set<int> sequences{currentSequence};
    for (int i = 10; i < length; i++) {
        currentSequence = ((currentSequence<<2)&clearMask);
        switch (s[i]) {
            case 'A':
                numToAdd = 0;
                break;
            case 'C':
                numToAdd = 1;
                break;
            case 'G':
                numToAdd = 2;
                break;
            case 'T':
                numToAdd = 3;
                break;
        }
        currentSequence |= numToAdd;
        if (!sequences.insert(currentSequence).second) {
            resultNums.insert(currentSequence);
        }
    }
   for (auto num : resultNums) {
        string toAdd(10,' ');
        for (int i=9;i>=0;i--) {
            switch (num&3) {
                case 0:
                    toAdd[i]='A';
                    break;
                case 1:
                    toAdd[i]='C';
                    break;
                case 2:
                    toAdd[i]='G';
                    break;
                case 3:
                    toAdd[i]='T';
                    break;
            }
            num>>=2;
        }
       result.push_back(toAdd);
    }
    return result;
}

void LeetCode187RepeatedDNASequences::Run() {
    string s="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Auxilaries::PrintVector(findRepeatedDnaSequences(s));
}
