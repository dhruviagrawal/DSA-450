 vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>res(nums.size(),-1);
        stack<int>s;
        for(int i=0;i<2*nums.size();i++)
        {
            while(!s.empty()&&nums[i%nums.size()]>nums[s.top()])
            {
                res[s.top()] = nums[i%nums.size()];
                s.pop();
            }
            if(i<nums.size())
                s.push(i);
        }
        return res;
    }
