class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int i,j,k,l,p=strs.size();
        vector<vector<int>> dp(m+1 , vector<int>(n+1));
        
        for(auto &s:strs)
        {
            int currOnes = count(s.begin(),s.end(),'1');
            int currZeros = s.size()-currOnes;
            
            for(j=n;j>=currOnes;j--)
            {
                for(i=m;i>=currZeros;i--)
                {
                    dp[i][j] = max(dp[i][j],1+dp[i-currZeros][j-currOnes]);
                }
            }
        }
        return dp[m][n];
    }
};
