class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    int i = 0;
    int mini = INT_MAX;
    while((i+m-1)<n){
        int diff = a[i+m-1] - a[i];
        mini = min(mini,diff);
        i++;
    }
    return mini;
    }   
};
