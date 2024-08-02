/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    pair<int,int> diameterFast(TreeNode* node){
        // code here 
        if(node == NULL){
            pair<int,int>p = make_pair(0,0);
            return p;
        }
        pair<int,int> left = diameterFast(node -> left);
        pair<int,int> right = diameterFast(node->right);
        int op1 = left.first;
        int op2 = right.first;
        int op3 = right.second + left.second ;
        
        pair<int,int>ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second,right.second)+1;
        
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first;
    }
};
