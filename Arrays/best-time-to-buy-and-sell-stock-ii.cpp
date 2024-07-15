class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;;
        int start = prices[0];
        for(int i = 1 ;i < prices.size() ; i++){
            if(prices[i] < start){
                start = prices[i];
            }
            else{
                int profit = prices[i] - start;
                start = prices[i];
                maxi += profit;
            }
        }
        return maxi;
    }
};
