// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
//using coin change permutation method that is trying the possibility of placing 
//all the items for every possible i
    // int knapSack(int n, int W, int val[], int wt[])
    // {
    //   int dp[W+1] = {0};
    //   for(int i=1;i<=W;i++)
    //   {
    //       //har position i ke liye saare weights try karke dekho
    //       for(int j=0;j<n;j++)
    //         {
    //             if(wt[j]<=i)
    //             {
    //                 dp[i] = max(dp[i],val[j]+dp[i-wt[j]]);
    //             }
    //         }
    //   }
    //   return dp[W];
    // }
    
//using strategy of coin change combination where we used to first take the effect of 
//each coin in the entire dp array, then the effect of the other one and so on
    int knapSack(int n, int W, int val[], int wt[])
    {
       int dp[W+1] = {0};
       for(int j=0;j<n;j++)
       {
           
            for(int i=1;i<=W;i++)
            {
                if(wt[j]<=i)
                {
                    dp[i] = max(dp[i],val[j]+dp[i-wt[j]]);
                }
            }
       }
       return dp[W];
    }
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends