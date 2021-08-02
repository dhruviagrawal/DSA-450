class Solution {
public:
    int rob(vector<int>& nums) {
        int inc = nums[0];
        int exc = 0;
        for(int i=1;i<nums.size();i++)
        {
            int newinc = nums[i] + exc;
            int newexc = max(inc,exc);
            
            inc = newinc;
            exc = newexc;
        }
        return max(inc,exc);
    }
};