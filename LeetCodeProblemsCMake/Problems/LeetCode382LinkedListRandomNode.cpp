//
// Created by saeed on 1/10/25.
//

#include "LeetCode382LinkedListRandomNode.h"

#include <random>

#include "../Auxilary/ListNode.h"


class Solution {
private:
    int length = 0;
    std::random_device random_device;
    ListNode* head = NULL;
public:
    Solution(ListNode* head) {
        auto node = head;
        this->head = head;
        while (node!=nullptr) {
            length++;
            node=node->next;
        }
    }

    int getRandom() {
        std::mt19937 gen(random_device());

        std::uniform_int_distribution<> distrib(0, length-1);
        int index = distrib(gen);
        auto node = head;
        for (int i=0;i<index;i++)
            node = node->next;
        return node->val;
    }
};
