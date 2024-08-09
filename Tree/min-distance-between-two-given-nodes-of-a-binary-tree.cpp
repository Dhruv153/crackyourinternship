class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* lca(Node*root, int a, int b){
            // base case
            if(!root){
                return nullptr;
            }
            if(root->data == a || root->data == b){
                return root;
            }
            
            Node*l = lca(root->left,a,b);
            Node*r = lca(root->right, a,b);
            
            if(l && r) return root;
            if(l) return l;
            else return r;
        }
    void getans(Node* root,int &ans,int sch,int i){
        if(root == nullptr) return;
        if(root->data == sch){
            ans = ans + i;
            return;
        }
        getans(root->left,ans,sch,i+1);
        getans(root->right,ans,sch,i+1);
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        int ans = 0;
        int i=0;
        Node* temp = lca(root,a,b);
        getans(temp,ans,a,i);
        getans(temp,ans,b,i);
        return ans;
   }
};
