#include "LeetCode3217DeleteNodesFromLinkedListPresentInArray.h"

#include <unordered_map>
#include <unordered_set>

#include "LeetCode206ReverseLinkedList.h"
using namespace std;

ListNode* LeetCode3217DeleteNodesFromLinkedListPresentInArray::modifiedList(vector<int>& nums, ListNode* head)
{
    unordered_set<int> numMap{};
    for (const int num : nums)
    {
        numMap.insert(num);
    }
    ListNode* previous=nullptr;
    auto node = head;
    auto newHead=head;
    while (node != nullptr)
    {
        if (numMap.contains(node->val))
        {
            if (previous!=nullptr)
            {
                previous->next = node->next;
                node = previous->next;
                continue;
            }
            newHead = node->next;
            node=node->next;
            continue;
        }
        previous = node;
        node = node->next;
    }
    return newHead;
}
