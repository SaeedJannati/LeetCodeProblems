//
// Created by saeed on 5/15/25.
//

#include "LeetCode2900LongestUnequalAdjacentGroupsSubsequenceI.h"
using  namespace  std;
 vector< string> LeetCode2900LongestUnequalAdjacentGroupsSubsequenceI::getLongestSubsequence(
     vector< string> &words,  vector<int> &groups) {
     int previousValue=groups[0];
     vector< string> result{};
     result.push_back(words[0]);
     int length=static_cast<int>( words.size());
     for(int i=1;i<length;i++) {
         if (previousValue==groups[i]) {
             continue;
         }
         previousValue=groups[i];
         result.push_back(words[i]);
     }
     return result;
}
