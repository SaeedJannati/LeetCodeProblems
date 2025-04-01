//
// Created by saeed on 4/1/25.
//

#ifndef LEETCODE147INSERTIONSORTLIST_H
#define LEETCODE147INSERTIONSORTLIST_H
#include "BaseProblem.h"


struct ListNode;

class LeetCode147InsertionSortList: BaseProblem {
private:
    ListNode* insertionSortList(ListNode* head);
    public:
    void Run() override;
};



#endif //LEETCODE147INSERTIONSORTLIST_H
