class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        solve(0,nums,result,subset);
        return result;
    }
    void solve(int idx,vector<int>& nums,vector<vector<int>>& result,vector<int>& subset){
        result.push_back(subset);
        for(int i = idx ; i < nums.size(); i++){
            if(i>idx && nums[i] == nums[i -1])
                continue;
            subset.push_back(nums[i]);
            solve(i+1,nums,result,subset);
            subset.pop_back();
        }
    }
};
