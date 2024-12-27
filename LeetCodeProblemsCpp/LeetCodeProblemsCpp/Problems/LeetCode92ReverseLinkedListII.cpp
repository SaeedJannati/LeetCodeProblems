#include "LeetCode92ReverseLinkedListII.h"

#include <iostream>

void LeetCode92ReverseLinkedListII::Run()
{
    auto head = ListNode(1);
    auto second = ListNode(2);
    head.next=&second;
    auto third = ListNode(3);
    second.next=&third;
    // auto fourth = ListNode(4);
    // third.next=&fourth;
    // auto fifth = ListNode(5);
    // fourth.next=&fifth;
    // auto sixth=ListNode(6,&fifth);
    // auto seventh=ListNode(7,&sixth);
    // PrintLinkedList(&head);
    int left = 1;
    int right = 2;
    PrintLinkedList(reverseBetween(&head, left, right));
}

ListNode* LeetCode92ReverseLinkedListII::reverseBetween(ListNode* head, int left, int right)
{
    if(head==nullptr)
        return head;
    if(left>=right )
        return head;
    ListNode* previous = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;
    ListNode* init = nullptr;
    for (int i = 0; i < right; i++)
    {
        next = current->next;
        if (i < left - 2)
        {
            previous = current;
            current = next;
            continue;
        }
        if (i == left - 2)
        {
            previous = current;
            current = next;
            init = current;
            continue;
        }
        current->next = previous;
        previous = current;
        current = next;
    }
    if (init != nullptr)
    {
        if (init->next != nullptr)
            if (init->next->next != nullptr)
                init->next->next = previous;
        init->next = current;
    }
    if(init==nullptr)
    {
        head->next=next;
        head=previous;
    }
    return head;
}

void LeetCode92ReverseLinkedListII::PrintLinkedList(ListNode* head)
{
    auto node = head;
    while (node != nullptr)
    {
        std::cout << node->val << ',';
        node = node->next;
    }
}
