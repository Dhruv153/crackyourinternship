/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(ListNode *head){
        ListNode *temp = head;
        int cnt= 0;
        while(temp != NULL){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt1 = countNodes(headA);
        int cnt2 = countNodes(headB);
        int diff = abs(cnt1 - cnt2);
        if(cnt1 > cnt2){
            while(diff--){
                headA = headA-> next;
            }
        }
        else{
            while(diff--){
                headB = headB-> next;
            }
        }
        while(headA != NULL && headB != NULL){
            if(headA == headB)
                return headA;
            headA = headA-> next;
            headB = headB-> next;
        }
        return NULL;
    }
};
