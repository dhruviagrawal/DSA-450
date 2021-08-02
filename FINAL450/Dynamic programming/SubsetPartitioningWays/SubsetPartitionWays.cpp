#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    
    //nth person is left alone and two cases arise for rest of the n-1 persons
    //n-1 persons form k teams
    //n-1 persons form k-1 teams
    //in the first case if the no of ways to make k teams is y(say) then nthe person 
    //can go in any of the k teams and generate a new way, so for each of the ways y 
    //we have y*k total ans for the first case
    //in the second case we have k-1 teams only so nth person is left with the only 
    //choice that is to make his own team separate which contributes only one way
    
    // total = k*y + x
    //f(k,n) = f(k-1,n-1) + f(k,n-1)*k
    int N,K;
    cin >> N >> K;
    int dp[K+1][N+1];
    
    for(int k=0;k<=K;k++)
    {
        for(int n=0;n<=N;n++)
        {
            if(k==0 || n==0 || n<k)
                dp[k][n] = 0;
            else if(n==k || k==1)
                dp[k][n] = 1;
            else{
                dp[k][n] = dp[k][n-1]*k + dp[k-1][n-1];
            }
        }
    }
    
    
 
    cout << dp[K][N] << endl;
}