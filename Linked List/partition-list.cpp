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
    ListNode* partition(ListNode* head, int x) {
        ListNode* list1 = new ListNode(0);
        ListNode* list2 = new ListNode(0);

        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* temp1 = head;
        while(temp1 != NULL){
            if(temp1->val < x){
                l1->next = temp1 ; 
                l1 = l1->next;
            }
            else{
                l2 -> next= temp1;
                l2 = l2->next;
            }
            temp1 = temp1->next;

        }
        l1 -> next = list2 ->next;
        l2-> next = NULL;
        return list1->next;
    }
};
