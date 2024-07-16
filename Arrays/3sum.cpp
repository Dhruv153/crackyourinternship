class Solution {
public:
    void twoSum(vector<int> &nums,int i ,int n1,vector<vector<int>>& result){\
        int j = nums.size() -1;
        while(i<j){
            if((nums[i] + nums[j])>n1)
                j--;
            else if((nums[i] + nums[j])<n1)
                i++;
            else{
                while(i < j && nums[i]==nums[i+1])i++;
                while(i < j && nums[j]==nums[j-1])j--;
                result.push_back({-n1,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0 ; i < n -2 ; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int n1 = -nums[i];
            twoSum(nums,i+1,n1,result);
        }
        return result;
    }
};
