class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                //if it is the last cell 
                if(i==m-1 && j==n-1){
                  dp[i][j] = grid[i][j];  
                }
                //if it is last row it has only one choice too go right
                else if(i==m-1){
                    dp[i][j] = grid[i][j] + dp[i][j+1];
                }
                //if it is the last column then it has onl one choice to go down
                else if(j==n-1){
                    dp[i][j] = grid[i][j] + dp[i+1][j];
                }
                else{
                    dp[i][j] = grid[i][j] + min(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};