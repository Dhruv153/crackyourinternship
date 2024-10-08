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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast != NULL && fast -> next ){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* curr = slow -> next , *prev =NULL;
        while(curr!=NULL){
            ListNode* forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;
        while(secondHalf != NULL){
            if(firstHalf -> val != secondHalf -> val){
                return false;
            }
            firstHalf = firstHalf -> next;
            secondHalf  = secondHalf -> next;
        }
        return true;
    }
};
