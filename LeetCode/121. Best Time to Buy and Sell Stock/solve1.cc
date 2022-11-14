class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int vmin = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < vmin) vmin = prices[i];
            else if (prices[i] - vmin > profit) profit = prices[i] - vmin;
        }
            
        return profit;
    }
};
