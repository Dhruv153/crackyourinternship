class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(int ind,string &str,string &ans,int k){
         if(k==0||ind>=str.size()){
            ans=max(str,ans);
            return;
         }
         char mx=str[ind];
         for(int i=ind; i<str.size(); i++){
              if(i==ind){
              solve(ind+1,str,ans,k);               
              }
              if(str[i]>mx){
              swap(str[ind],str[i]);
              solve(ind+1,str,ans,k-1); 
              swap(str[ind],str[i]);                  
              }
         } 
    }
    string findMaximumNum(string str, int k)
    {
      string ans;
      int ind=0;
      solve(ind,str,ans,k);
      return ans;
    }
};