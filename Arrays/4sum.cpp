class Solution {
public:
    void twoSum(vector<int> &nums,int i ,long long n2,vector<vector<int>>& result,long long org_T,long long n1){
        int j = nums.size() -1;
        while(i<j){
            long long sum = nums[i] + nums[j];
            if(sum>n2)
                j--;
            else if(sum<n2)
                i++;
            else{
                while(i < j && nums[i]==nums[i+1])i++;
                while(i < j && nums[j]==nums[j-1])j--;
                result.push_back({static_cast<int>(org_T-n1),static_cast<int>(n1-n2),nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }
    void threeSum(vector<int>& nums,vector<vector<int>>& result,long long n1,int I,long long org_T) {
        int n = nums.size();
        for(int i = I ; i < n -2 ; i++){
            if(i > I && nums[i] == nums[i-1]){
                continue;
            }
            long long n2 = n1-nums[i];
            twoSum(nums,i+1,n2,result,org_T,n1);
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0 ; i < n-3 ; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            long long n1 =(long long)target - nums[i];
            threeSum(nums,result,n1,i+1,target);
        }
        return result;
    }
};
