class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n =cardPoints.size();
        int left = 0;
        int right = n - k;
        int sum = accumulate(cardPoints.end()-k,cardPoints.end(),0);
        int maxSum = sum;
        while(right < n){
            sum += ( cardPoints[left]-cardPoints[right]);
            maxSum = max(sum,maxSum);
            left++;
            right++;
        }
        return maxSum;
    }
};
