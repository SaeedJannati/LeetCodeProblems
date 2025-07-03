//
// Created by saeed on 7/3/25.
//

#include "LeetCode3304FindTheKthCharacterInStringGameI.h"

#include <iostream>
#include <ostream>
#include <string>
using  namespace std;
void GetString(string current,int indexBefore,int k,char & result) {
    int length=current.length();
    if (length+indexBefore>=k) {
        k-=indexBefore;
        char target=current[k-1];
        result=target<'z'?target+1:'a';
        return;
    }
    for (int i=0;i<length;i++) {
        char target=current[i];
        target=target<'z'?target+1:'a';
        current+=target;
    }
    indexBefore+=length;
    GetString(current,indexBefore,k,result);
}
char LeetCode3304FindTheKthCharacterInStringGameI::kthCharacter(int k) {
    if (k==1)
        return 'a';
    char result=0;
    GetString("a",1,k,result);
    return result;
}

void LeetCode3304FindTheKthCharacterInStringGameI::Run() {
    int k=1;
    cout<< kthCharacter(k)<<endl;
}
