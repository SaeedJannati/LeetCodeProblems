#pragma once

class LeetCode430FlattenAMultilevelDoublyLinkedList
{
    class Node
    {
    public:
        int val;
        Node* prev;
        Node* next;
        Node* child;
    };

    Node* flatten(Node* head)
    {
        auto node = head;
        while (node != nullptr)
        {
            SetNext(node);
            node = node->next;
        }
        return head;
    }

    void SetNext(Node* node)
    {
        if (node->child == nullptr)
            return;
        auto next = node->next;
        node->next = node->child;
        auto childrenHead = node->child;
        childrenHead->prev = node;
        node->child = nullptr;
        Node* previous = nullptr;
        while (childrenHead != nullptr)
        {
            if (childrenHead->child != nullptr)
            {
                SetNext(childrenHead);
            }
            previous = childrenHead;
            childrenHead = childrenHead->next;
        }
        previous->next = next;
        if (next != nullptr)
            next->prev = previous;
    }
};
