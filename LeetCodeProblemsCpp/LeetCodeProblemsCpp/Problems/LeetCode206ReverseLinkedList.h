#pragma once
#include "BaseProblem.h"
struct ListNode;

class LeetCode206ReverseLinkedList : BaseProblem
{
public:
    void Run() override;
    void PrintLinkedList(ListNode* head);

private:
    ListNode* reverseList(ListNode* head);
};

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr)
    {
    }

    ListNode(int x) : val(x), next(nullptr)
    {
    }

    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};
