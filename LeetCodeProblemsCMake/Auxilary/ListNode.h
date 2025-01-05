//
// Created by saeed on 1/5/25.
//

#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
#include <string>
#include <vector>


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }

    ~ListNode() {
        DeleteNext();
    }

    void DeleteNext() {
        if (next != nullptr) {
            next->DeleteNext();
            delete next;
            next = nullptr;
        }
    }

    static ListNode *CreateListFromVector(const std::vector<int> &vector) {
        const auto head = new ListNode(vector[0]);
        auto cur = head;
        for (int i = 1; i < vector.size(); i++) {
            cur->next = new ListNode(vector[i]);
            cur = cur->next;
        }
        return head;
    }

    static void PrintList(const ListNode *head) {
        if (head == nullptr) return;
        std::string s;
        while (head != nullptr) {
            s += std::to_string(head->val);
            s += ' ';
            head = head->next;
        }
        std::cout << s << '\n';
    }
};


#endif //LISTNODE_H
