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
    ListNode* reverse(ListNode* l1){
        ListNode* prev = NULL;
        ListNode* forw = NULL;
        ListNode* curr = l1;
        while(curr != NULL){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0 ;
        ListNode* first = reverse(l1);
        ListNode* second = reverse(l2);
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
        return reverse(dummy.next);
    }
};
