class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        solve( 1,n ,k ,result , temp);
        return result;
    }
    void solve(int start, int n ,int k ,vector<vector<int>>& result,vector<int> temp){
        if(temp.size() == k){
            result.push_back(temp);
            return;
        }
        for(int i = start ; i <= n ;i++){
            temp.push_back(i);
            solve(i+1 ,n ,k ,result , temp);
            temp.pop_back();
        }
    }
};
