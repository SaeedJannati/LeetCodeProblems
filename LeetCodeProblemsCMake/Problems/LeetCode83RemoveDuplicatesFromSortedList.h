//
// Created by saeed on 1/5/25.
//

#ifndef LEETCODE83REMOVEDUPLICATESFROMSORTEDLIST_H
#define LEETCODE83REMOVEDUPLICATESFROMSORTEDLIST_H
#include "BaseProblem.h"


struct ListNode;

class LeetCode83RemoveDuplicatesFromSortedList: BaseProblem {
    private:
    ListNode* deleteDuplicates(ListNode* head);
    public:
    void Run() override;
};



#endif //LEETCODE83REMOVEDUPLICATESFROMSORTEDLIST_H
