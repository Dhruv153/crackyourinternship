class Solution {
public:
    int cnt;
    void merge(vector<int> &arr, int s, int e) {

    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}

void countPairs(vector<int> &arr , int start , int mid , int end){
    int right = mid+1;
    for(int i = start ; i <= mid ;i++){
        while(right <= end && arr[i] > 2LL*arr[right]){
            right++;
        }
        cnt+= (right - (mid+1));
    }
}

// Merge Sort (Divide and conquer algorith)
void mergeSort(vector<int> &arr, int start, int end){
    // Base Case
    if(start >= end){
        // Invalid Array
        return;
    }
    // Step 01: Find mid and break the original array into two equal part
    int mid = start + (end - start)/2;

    // Step 02: Recursion call for sorting left and right part
    // Recursive call for left part
    mergeSort(arr, start, mid);
    // Recursive call for right part
    mergeSort(arr, mid+1, end);
    countPairs(arr , start , mid , end);
    // Step 03: Merge two sorted arrays
    merge(arr,start,end);
}

    int reversePairs(vector<int>& nums) {
        cnt = 0;
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return cnt;
    }
};
