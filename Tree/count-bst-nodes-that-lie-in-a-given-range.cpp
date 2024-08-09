class Solution{
public:
    void solve(Node* root ,int l ,int r ,int &cnt){
        if(root == NULL){
            return;
        }
        if(root->data >= l && root->data <= r)
            cnt++;
        solve(root->left,l,r,cnt);
        solve(root->right,l,r,cnt);
    }
    int getCount(Node *root, int l, int h)
    {
        int count = 0;
        solve(root,l,h,count);
        return count;
    }
};
