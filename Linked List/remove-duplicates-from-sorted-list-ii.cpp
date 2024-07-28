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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (head != nullptr) {
            bool duplicate = false;
            while (head->next != nullptr && head->val == head->next->val) {
                ListNode* temp = head->next;
                head->next = head->next->next;
                delete temp;
                duplicate = true;
            }
            if (duplicate) {
                ListNode* temp = head;
                prev->next = head->next;
                head = head->next;
                delete temp;
            } else {
                prev = head;
                head = head->next;
            }
        }

        return dummy.next;
    }
};
