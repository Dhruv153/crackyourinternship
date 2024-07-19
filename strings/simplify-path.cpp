class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string result = "";
        string token = "";
        stack<string> st;
        while(getline(ss,token,'/')){
            if(token == "." || token == ""){
                continue;
            }
            if(token != ".."){
                st.push(token);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        if(st.empty()){
            return "/";
        }
        while(!st.empty()){
            result = "/" + st.top() + result;
            st.pop();
        }
        return result;
    }
};
