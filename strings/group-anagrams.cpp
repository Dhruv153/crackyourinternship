class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> map;
        for(auto a : strs){
            string s = a;
            sort(s.begin(),s.end());
            map[s].push_back(a);
        }
        vector<vector<string>> ans;
        for(auto a : map){
            ans.push_back(a.second);
        }
        return ans;
    }
};
