class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        int mid = nums[n/2];
        for(auto i : nums){
            ans+= abs(mid - i);
        }
        return ans;
    }
};
