class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        priority_queue<P,vector<P>,greater<P>> pq;
        for(auto i:mp){
            int freq= i.second;
            int value = i.first;
            pq.push({freq,value});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
