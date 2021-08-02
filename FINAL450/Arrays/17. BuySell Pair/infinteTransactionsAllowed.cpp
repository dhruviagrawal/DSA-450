class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //initialise your buy cell pair to prices[0]
        //then travel through the array till you are getting a monotonous increase
        //in the graph, once the graph begins to fall sell you pair
        //and reset your buy cell pair again to the minima of the graph
        int buy = prices[0],sell = prices[0],ans = 0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>=prices[i-1])
            {
                sell = prices[i];
            }
            else{
               ans +=  sell - buy;
               buy = prices[i],sell = prices[i];
            }
            
        }
            ans += sell - buy;
        return ans;
    }
};