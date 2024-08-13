class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
        pq.push(1);
        for(int i=0;i<n-1;++i){
            long long int top_value = pq.top();
            pq.pop();
            while(pq.size()>0 && pq.top()==top_value){
                pq.pop();
            }
            pq.push(2*top_value);
            pq.push(3*top_value);
            pq.push(5*top_value);
        }
        return pq.top();
    }
};
