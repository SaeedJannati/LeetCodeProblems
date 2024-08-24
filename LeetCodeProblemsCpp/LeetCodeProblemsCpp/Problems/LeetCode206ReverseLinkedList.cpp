#include "LeetCode206ReverseLinkedList.h"

#include <algorithm>
#include <iostream>

void LeetCode206ReverseLinkedList::Run()
{
    ListNode head = ListNode(1);
    ListNode second = ListNode(2);
    ListNode third = ListNode(3);
    ListNode fourth = ListNode(4);
    head.next = &second;
    second.next = &third;
    third.next = &fourth;
    PrintLinkedList(reverseList(&head));
}

void LeetCode206ReverseLinkedList::PrintLinkedList(ListNode* head)
{
    auto node = head;
    while (node != nullptr)
    {
        std::cout << node->val << ',';
        node = node->next;
    }
}

ListNode* LeetCode206ReverseLinkedList::reverseList(ListNode* head)
{
    ListNode* previous = nullptr;
    ListNode* current = head;
    ListNode* next=nullptr;
    while (current!=nullptr)
    {
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    return previous;
}
