class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    vector<pair<int,int>> ans(n);
	    int cnt = 0;
	    for(int i = 0 ; i < nums.size() ; i++){
	        ans[i]={nums[i],i};
	    }
	    sort(ans.begin(),ans.end());
	    for(int i = 0 ; i < nums.size() ; i++){
	        if(ans[i].second == i){
	            continue;
	        }
	        else{
	            cnt++;
	            swap(ans[i],ans[ans[i].second]);
	            i--;
	        }
	    }
	    return cnt;
	}
};
