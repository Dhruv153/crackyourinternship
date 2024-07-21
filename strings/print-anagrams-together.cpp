class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(auto &ch : string_list){
            string a = ch;
            sort(ch.begin(),ch.end());
            mp[ch].push_back(a);
        }
        for(auto a : mp){
            ans.push_back(a.second);
        }
        return ans;
    }
};
