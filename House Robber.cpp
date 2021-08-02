class Solution {
public:

    int choose(vector<int>&nums,int X,vector<int>&dp)
    {
        if(X<0)
            return 0;
        if(dp[X]==-1)
        return dp[X]=max(choose(nums,X-2,dp)+nums[X],choose(nums,X-1,dp));
        else return dp[X];
    }
    int rob(vector<int>& nums) {
            vector<int> dp(100001,-1);
        return choose(nums,nums.size()-1,dp);
    }
};
