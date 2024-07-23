class Solution {
  public:
    // Function to find minimum number of pages.
    int isPossible(int A[],int N,int M,int mid){
        int pageSum=0;
        int count=1;
        for(int i=0;i<N;i++){
            if(A[i]>mid){
                return false;
            }
            if(A[i]+pageSum>mid){
                count++;
                pageSum=A[i];
            
                 if(count>M){
                return false;
                 }
            }
            else{
                pageSum=pageSum+A[i];
            }
        }
        
        return true;
    }

    long long findPages(int N, int A[], int M) {
        // code here
        if(M>N){
            return -1;
        }
        int ans=-1;
        int start=0;
        int end= accumulate(A,A+N, 0);
       
        while(start<=end){
             int mid=(start+end)>>1;
        if(isPossible(A,N,M,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        
        }
        return ans;
    }
};
