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
    void helper(TreeNode* root, int low, int high, int &ans){
        if(root == NULL)
            return ;

        if (low <= root->val && root->val <= high)
            ans += root->val;

        if (root->val > low) 
            helper(root->left, low, high, ans);

        if (root->val < high)
            helper(root->right, low, high, ans);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0; 
        helper(root , low ,high ,ans);
        return ans;
    }
};
