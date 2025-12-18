class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();i++){
            int cost = prices[i] - mini;
            mini = min(mini,prices[i]);
            profit = max(cost,profit);
        }
        return profit;
    }
};