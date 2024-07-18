class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string ans;
        int n = strs.size();
        string v1=strs[0],v2=strs[n-1];
        for(int i = 0;i<min(v1.size(),v2.size());i++){
            if(v1[i]!=v2[i]){
                return ans;
            }
            else
                ans+=v1[i];
        }
        return ans;
    }
};
