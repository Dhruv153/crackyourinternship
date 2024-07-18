class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int left = 0;
        int right = n -1;
        while(right < haystack.size()){
            string curr = haystack.substr(left,n);
            if(curr == needle)
                return left;
            left++;
            right++;
        }
        return -1;
    }
};
