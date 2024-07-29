class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                if (!s1.empty())
                    s1.pop();
            } else {
                s1.push(s[i]);
            }
        }
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == '#') {
                if (!s2.empty())
                    s2.pop();
            } else {
                s2.push(t[i]);
            }
        }
        while (!s1.empty() && !s2.empty()) {
            char temp1 = s1.top();
            char temp2 = s2.top();
            s1.pop();
            s2.pop();
            if (temp1 != temp2)
                return false;
        }
        return s1.empty() && s2.empty();
    }
};
