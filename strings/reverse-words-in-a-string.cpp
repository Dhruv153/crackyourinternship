#include <fstream>
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string result = "";
        string token = "";
        stack<string> st;
        while(ss >> token){
            if(token != " "){
                st.push(token);
            }
            else
                continue;
        }
        while(!st.empty()){
            result+=st.top();
            st.pop();
            if(!st.empty())
                result+= " ";
        }
        return result;
    }
};
