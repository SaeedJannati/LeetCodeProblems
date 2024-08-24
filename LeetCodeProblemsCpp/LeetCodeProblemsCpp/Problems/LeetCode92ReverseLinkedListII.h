#pragma once
#include "BaseProblem.h"
struct ListNode;
class LeetCode92ReverseLinkedListII:BaseProblem
{
public:
    void Run() override;
private:
    ListNode* reverseBetween(ListNode* head, int left, int right);
    void PrintLinkedList(ListNode* head);
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
