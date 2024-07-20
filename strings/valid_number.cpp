class Solution {
public:
    bool isNumber(string s) {
        bool digitSeen = false , eSeen = false , dotSeen = false;
        for(int i = 0 ; i < s.length() ; i++ ){
            if(isdigit(s[i])){
                digitSeen = true;
            }
            else if(s[i]=='e' || s[i] == 'E'){
                if(!digitSeen || eSeen || i == s.length() - 1){
                    return false;
                }
                eSeen = true;
                digitSeen = false;
            }
            else if(s[i] == '.'){
                if(dotSeen || eSeen)
                    return false;
                dotSeen = true;
            }
            else if(s[i] == '+' || s[i] == '-'){
                if (i == 0 || s[i-1] == 'e' || s[i-1] == 'E') {
                    continue;
                } else {
                    return false;
                }
            }
            else
                return false;
        }
        return digitSeen;
    }
};
