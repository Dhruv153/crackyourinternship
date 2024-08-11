void inorder(struct Node *root,vector<int>& in){
    if(root == NULL)
        return;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

float findMedian(struct Node *root)
{
      //Code here
      vector<int> in;
      inorder(root,in);
      int n = in.size();
      int mid = (0+n)/2;
      if(n % 2 != 0){
          return (float)in[mid];
      }
      else{
          return (float)(in[mid-1]+in[mid])/2;
      }
}
