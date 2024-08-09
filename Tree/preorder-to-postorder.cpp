class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    Node* solve(int arr[], int min, int max, int& i,int size){
        // int n = arr.size();
        if( i >= size ) 
            return NULL;
        if(arr[i] > max || arr[i] < min) 
            return NULL;
        Node* root = newNode(arr[i++]);
        root->left = solve(arr, min, root->data, i,size);
        root->right = solve(arr, root->data, max, i,size);
        return root;
    }
    Node* Bst(int pre[], int size) {
        // code here
        int i =0;
        Node* root = solve(pre,INT_MIN,INT_MAX,i,size);
        return root;
    }
};
