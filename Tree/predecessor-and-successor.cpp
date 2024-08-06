void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        Node* temp = root;
        while(temp != NULL &&temp -> key != key){
            if(temp -> key > key){
                suc = temp;
                temp = temp -> left;
            }
            else{
                pre = temp;
                temp = temp -> right;
            }
        }
        
        if (temp == NULL) return;
        
       if (temp->left != NULL) {
        Node* lefttree = temp->left;
        while (lefttree->right != NULL) {
            lefttree = lefttree->right;
        }
        pre = lefttree;
    }
        if (temp->right != NULL) {
        Node* righttree = temp->right;
        while (righttree->left != NULL) {
            righttree = righttree->left;
        }
        suc = righttree;
    }
    }
