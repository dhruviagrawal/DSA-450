class Solution {
public:
    int dp[5001];
    int change(int amount, vector<int>& coins) {
        memset(dp,0,sizeof(dp));
        int n = coins.size();
        dp[0] = 1;
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<=amount;i++)
            {
                if(coins[j]<=i)
                dp[i] += dp[i-coins[j]];
            }
        }
        return dp[amount];
    }
};