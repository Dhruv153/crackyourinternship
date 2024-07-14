class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for(auto num:nums){
            if(num == 0)
                cnt0++;
            if(num == 1)
                cnt1++;
            if(num == 1)
                cnt2++;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(cnt0){
                nums[i] = 0;
                cnt0--;
            }
            else if(cnt1){
                nums[i] = 1;
                cnt1--;
            }
            else{ 
                nums[i] =2;
                cnt2--;
            }
        }
    }
};
