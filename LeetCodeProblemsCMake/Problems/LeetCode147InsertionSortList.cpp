//
// Created by saeed on 4/1/25.
//

#include "LeetCode147InsertionSortList.h"

#include "../Auxilary/ListNode.h"
using namespace std;

ListNode *LeetCode147InsertionSortList::insertionSortList(ListNode *head) {
    ListNode *current = head;
    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    while (current != nullptr) {
        next = current->next;
        ListNode *node = head;
        bool moved = false;
        if (current->val < node->val) {
            if (prev != nullptr) {
                prev->next = next;
            }
            current->next = head;
            head = current;
            current = next;
            continue;
        }
        while (node != current) {
            if (node->val <= current->val && node->next->val > current->val) {
                if (prev != nullptr) {
                    prev->next = next;
                }
                current->next = node->next;
                node->next = current;
                moved = true;
                current = next;
                break;
            }
            node = node->next;
        }
        if (moved)
            continue;
        prev = current;
        current = next;
    }
    return head;
}

void LeetCode147InsertionSortList::Run() {
    auto head = ListNode::CreateListFromVector(vector<int>{-1,5,3,4,0});
    head = insertionSortList(head);
    ListNode::PrintList(head);
}
