class Solution {
public:
    string minWindow(string s, string t) {
        int count = t.length();
        int n = s.length();
        if(count > n)
            return "";
        unordered_map<char,int> mp;
        for(auto &ch : t){
            mp[ch]++;
        }
        int i = 0 , j = 0;
        int minWindow = INT_MAX;
        int start_i = 0;
        while(j < n){
            if(mp[s[j]] > 0)
                count--;
            mp[s[j]]--;
            while(count == 0){
                int curr = j-i+1;
                if(minWindow > curr){
                    minWindow = curr;
                    start_i = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0){
                    count++;
                }
                i++;
            }
            j++;
        }
        return minWindow == INT_MAX ? "" : s.substr(start_i,minWindow);
    }
};
