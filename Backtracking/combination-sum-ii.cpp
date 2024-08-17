class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> curr;
        solve(candidates,target,result,curr,0);
        return result;
    }
    void solve(vector<int>& arr,int target,vector<vector<int>> &result,vector<int> curr,int idx){
        if(target < 0)
            return;
        if(target == 0){
            result.push_back(curr);
            return;
        }
        for(int i = idx ; i < arr.size() ;i++){
            if(i>idx && arr[i] == arr[i-1])
                continue;
            curr.push_back(arr[i]);
            solve(arr,target-arr[i],result,curr,i+1);
            curr.pop_back();
        }
    }
};
