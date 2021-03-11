class Solution {
private:
public:
	int minSwaps(vector<int>&nums){
	    // Code here
	    int n = nums.size();
	    pair<int,int>posn[n];
	    for(int i=0;i<n;i++)
	    {
	        posn[i].first = nums[i];
	        posn[i].second = i;
	    }
	    sort(posn,posn+n);
	    int ans = 0;
	    vector <bool> vis(n,false);
	    for(int i=0;i<n;i++)
	    {
	        if(vis[i]==true || posn[i].second == i)
	        continue;
	        int j = i;
	        int cswap = 0;
	        while(!vis[j])
	        {
	            vis[j] = 1;
	            j = posn[j].second;
	            cswap++;
	        }
	        if(cswap)
	        ans+=cswap-1;
	    }
	    return ans;
	}
};
