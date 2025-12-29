//
// Created by saeed on 12/29/25.
//

#include "LeetCode756PyramidTransitionMatrix.h"

#include <unordered_map>
using namespace std;
void canBuild(vector<byte>& lastRow,vector<byte>&currentRow,unordered_map<byte,vector<byte>>& allowedMap,int index,bool & result) {
    if (result)
        return;
    if (index==lastRow.size()) {
        if (currentRow.size()==1) {
            result=true;
            return;
        }
        vector<byte> nextRow{};
        canBuild(currentRow,nextRow,allowedMap,1,result);
        return;
    }
    if (allowedMap.contains(lastRow[index-1]|lastRow[index]<<3)) {
        for (auto item:allowedMap[lastRow[index-1]|lastRow[index]<<3]) {
            currentRow.push_back(item);
            canBuild(lastRow,currentRow,allowedMap,index+1,result);
            currentRow.pop_back();
        }
    }
}
bool LeetCode756PyramidTransitionMatrix::pyramidTransition(string bottom, vector<string> &allowed) {
    auto allowedMap= unordered_map<byte,vector<byte>>{};
    for ( auto & triplet:allowed) {
        auto key=byte((triplet[0]-'A')|((triplet[1]-'A')<<3));
        if (!allowedMap.contains(key)) {
            allowedMap[key]={};
        }
        allowedMap[key].emplace_back(byte(triplet[2]-'A'));
    }
    auto lastRow=vector<byte>{};
    for (int i=0,e=bottom.size();i<e;i++) {
        lastRow.push_back(byte(bottom[i]-'A'));
    }
    bool result=false;
    auto currentRow=vector<byte>{};
    canBuild(lastRow,currentRow,allowedMap,1,result);
    return result;
}
