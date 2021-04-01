// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int mod = 1000000007;
    long long numberOfWays(long long N) {
        //code here
        
        long long dp[N+1];
        
        for(long long i=1;i<=N;i++)
        {
            if(i==1)
                dp[i] = 1;
            else if(i==2)
                dp[i] = 2;
            else{
                dp[i] = (dp[i-1] + dp[i-2])%mod;
            }
        }
        
        return (dp[N])%mod;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}  // } Driver Code Ends