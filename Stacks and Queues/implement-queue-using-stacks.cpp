class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        // stack<int> s1;
        // stack<int> s2;
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s1.empty()){
            return -1;
        }
        while(!s1.empty()){
            int temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        int ans = s2.top();
        s2.pop();
        while(!s2.empty()){
            int temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        return ans;
    }
    
    int peek() {
        if(s1.empty()){
            return -1;
        }
        while(!s1.empty()){
            int temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        int ans = s2.top();
        while(!s2.empty()){
            int temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        return ans;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
