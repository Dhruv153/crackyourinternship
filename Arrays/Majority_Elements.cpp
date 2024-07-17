class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        int ans,maxNum = 0;
        for(auto i : mp){
            if(i.second > maxNum){
                ans = i.first;
                maxNum = i.second;
            }
        }
        return ans;
    }
};
