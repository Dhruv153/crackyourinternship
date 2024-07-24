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
    int getDecimalValue(ListNode* head) {
        vector<int> binary;
        if(head->next == NULL){
            return head->val;
        }
        while(head != NULL){
            binary.push_back(head->val);
            head = head-> next;
        }       
        int ans = 0;
        int j = binary.size() -1;
        for(int i = 0 ; i < binary.size() ; i++){
            ans+= binary[i] * pow(2,j);
            j--;
        }
        return ans;
    }
};
