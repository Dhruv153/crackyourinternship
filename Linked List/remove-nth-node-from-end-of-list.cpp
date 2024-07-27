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
        while(temp){
            temp = temp -> next;
            cnt++;
        }
        // cout<<cnt;
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = countNodes(head);
        int rem = count - n ;
        ListNode* temp = head;
        if (rem == 0) {
            ListNode* newHead = head->next;
            return newHead;
        }
        for(int i = 1 ; i < rem ; i++){
            temp= temp->next;
        }
        temp -> next = temp -> next-> next;
        return head;
    }
};
