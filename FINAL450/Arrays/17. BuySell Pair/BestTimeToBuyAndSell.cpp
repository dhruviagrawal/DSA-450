class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profitIfSoldToday,ans = INT_MIN;
        int leastSoFar = INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            leastSoFar = min(leastSoFar,prices[i]);
            profitIfSoldToday = prices[i] - leastSoFar;
            ans = max(profitIfSoldToday,ans);
        }
        
        return ans;
    }
};