class Solution {
  public:
    void solve(Node *root, vector<int> &arr)
{
    if (!root)
        return;
    solve(root->left, arr);
    arr.push_back(root->data);
    solve(root->right, arr);
}
Node *bToDLL(Node *root)
{
    vector<int> arr;
    solve(root, arr);
    if (arr.empty())
        return NULL;
    Node *head = new Node(arr[0]);
    Node *tail = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        tail->right = temp;
        temp->left = tail;
        tail = temp;
    }
    return head;
}
};
