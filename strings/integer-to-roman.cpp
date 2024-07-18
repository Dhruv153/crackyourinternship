class Solution {
public:
    string intToRoman(int num) {
        static vector<int> v{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        static vector<string> s{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans = "";
        for(int i = 0 ; i < 13 ; i++){
            if(num == 0)
                break;
            int times = num / v[i];
            while(times--)
                ans+=s[i];
            num = num % v[i];
        }
        return ans;
    }
};
