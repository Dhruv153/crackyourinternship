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
public:
    void preOrder(TreeNode* root, vector<int>& pre){
        if(root == NULL)
            return;
        pre.push_back(root->val);
        preOrder(root->left,pre);
        preOrder(root->right,pre);
    }
    
    void flatten(TreeNode* root) {
        vector<int> pre;
        preOrder(root,pre);
        if(pre.size() == 1 ||pre.size() == 0)
            return;
        root -> left =NULL;
        root -> right = NULL;
        TreeNode* temp = root;
        for(int i = 1 ; i < pre.size() ;i++){
            temp ->left = NULL;
            TreeNode* tem = new TreeNode(pre[i]);
            temp -> right = tem;
            temp = temp->right;
        }
    }
};
