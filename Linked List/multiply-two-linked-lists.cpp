class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long int num1 = 0;
        long long int num2 = 0;
        while(first != NULL){
            num1 = (num1 * 10 + first -> data) % 1000000007;
            first = first -> next;
        }
        while(second != NULL){
            num2 = (num2 * 10 + second -> data) % 1000000007;
            second = second -> next;
        }
        return (num1*num2) % 1000000007;
    }
};
