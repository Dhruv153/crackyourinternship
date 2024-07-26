/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0 ;
        ListNode* first = l1;
        ListNode* second = l2;
        ListNode dummy;
        ListNode* newList = &dummy;
        while (first != nullptr || second != nullptr || carry) {
            int sum = carry;
            if (first != nullptr) {
                sum += first->val;
                first = first->next;
            }
            if (second != nullptr) {
                sum += second->val;
                second = second->next;
            }
            carry = sum / 10;
            newList->next = new ListNode(sum % 10);
            newList = newList->next;
        }
        return dummy.next;
    }
};
