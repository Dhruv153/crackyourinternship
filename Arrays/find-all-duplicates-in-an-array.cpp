class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto n : nums){
            mp[n]++;
        }
        for(auto n:mp){
            if(n.second >= 2 ){
                ans.push_back(n.first);
            }
        }
        return ans;
    }
};
