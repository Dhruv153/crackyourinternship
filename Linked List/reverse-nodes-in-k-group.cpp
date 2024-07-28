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
    int countNodes(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            temp= temp -> next;
            cnt++;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
            return head;
        int cnt = 0;
        int length = countNodes(head);
        ListNode* forward = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (cnt < k && curr != NULL && length - k>= 0) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            cnt++;
        }
        if(cnt >= k && length - k >= k)
            head->next=reverseKGroup(forward,k);
        else{
            head -> next = forward;
        }
        return  prev;
    }
};
