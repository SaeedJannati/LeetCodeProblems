#include "LeetCode1290ConvertBinaryNumberInALinkedListToInteger.h"

int LeetCode1290ConvertBinaryNumberInALinkedListToInteger::getDecimalValue(ListNode* head)
{
    int result{};
    auto node = head;
    while (node!=nullptr)
    {
        result|= node->val;
        result <<= 1;
        node = node->next;
    }
    return result>>1;
}
