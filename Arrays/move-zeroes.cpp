class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n=a.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(a[i]!=0){
                a[j]=a[i];
                j++;
            }
        }
        for(;j<n;j++)
        a[j]=0;
    }
};
