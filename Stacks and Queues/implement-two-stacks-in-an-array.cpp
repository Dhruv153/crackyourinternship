class twoStacks {
  public:
    int arr[101];
    int cnt1;
    int cnt2;
    twoStacks() {
        cnt1 = 0;
        cnt2 = 100;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        if(cnt2 != (cnt1+1)){
            arr[cnt1] = x;
            cnt1++;
        }
    }
    
    // Function to push an integer into the stack2.
    void push2(int x) {
        if(cnt2-1 != cnt1){
            arr[cnt2] = x;
            cnt2--;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(cnt1 == 0){
            return -1;
        }
        else{
            cnt1--;
            return arr[cnt1];
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(cnt2 == 100){
            return -1;
        }
        else{
            cnt2++;
            return arr[cnt2];
        }
    }
};
