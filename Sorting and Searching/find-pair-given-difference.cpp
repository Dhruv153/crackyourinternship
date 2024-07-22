class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int i =0 ,j = 1;
        while(i<n && j < n){
            if(i!=j && arr[j] - arr[i] == x)
                return true;
            else if(arr[j] - arr[i] < x)
                j++;
            else
                i++;
        }
        return -1;
    }
};




bool findPair(int arr[], int size, int n){
    //code
    unordered_map<int,int> map;
    for(int i = 0; i< size ; i++){
        map[arr[i]]++;
        if(n == 0 && map[arr[i]] > 1){
            return true;
        }
    }
    if(n==0)
    return false;
    for(int i = 0;i< size;i++){
        int sum = n + arr[i];
        if(map.find(sum) != map.end())
        return true;
    }
    return false;
}
