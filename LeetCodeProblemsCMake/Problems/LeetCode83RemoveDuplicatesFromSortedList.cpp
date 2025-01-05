//
// Created by saeed on 1/5/25.
//

#include "LeetCode83RemoveDuplicatesFromSortedList.h"

#include "../Auxilary/ListNode.h"

ListNode * LeetCode83RemoveDuplicatesFromSortedList::deleteDuplicates(ListNode *head) {
    if (head==nullptr)
        return head;
    if (head->next==nullptr)
        return head;
    ListNode* current=head;
    ListNode* previous=nullptr;
    while(current!=nullptr) {
        if (previous!=nullptr && current !=nullptr)
            if (previous->val==current->val) {
                previous->next=current->next;
                current=current->next;
                continue;
            }
        previous=current;
        current=current->next;
    }
    return head;
}

void LeetCode83RemoveDuplicatesFromSortedList::Run() {
    ListNode* head=ListNode::CreateListFromVector({1,1,1});
    deleteDuplicates(head);
    ListNode::PrintList(head);
    delete head;
}
