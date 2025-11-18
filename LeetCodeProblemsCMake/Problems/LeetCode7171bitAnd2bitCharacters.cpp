//
// Created by saeed on 11/18/25.
//

#include "LeetCode7171bitAnd2bitCharacters.h"

#include <iostream>
using namespace std;
void canBeFormed(vector<int>& bits,int index,bool & result) {
    if (result)
        return;
    if (index==-1) {
        result=true;
        return;
    }
    if (bits[index]==0) {
        canBeFormed(bits,index-1,result);
    }
    if (index>0) {
        if (bits[index-1]==0)
            return;
        canBeFormed(bits,index-2,result);
    }
}
bool LeetCode7171bitAnd2bitCharacters::isOneBitCharacter(vector<int> &bits) {
    int length=static_cast<int>(bits.size());
    if (length==0) {
        return bits[0]==0;
    }
    if (bits[length-1]==1)
        return false;
    if (bits[length-2]==0) {
        return true;
    }
    bool result=false;
    canBeFormed(bits,length-3,result);
    return !result;
}

void LeetCode7171bitAnd2bitCharacters::Run() {
    vector<int> bits={1,0,1,1,0};
    cout<< isOneBitCharacter(bits)<<'\n';
}
