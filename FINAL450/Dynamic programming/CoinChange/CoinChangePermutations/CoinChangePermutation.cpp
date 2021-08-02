#include<bits/stdc++.h>
using namespace std;
void coinChangePermutations(int coins[],int n,int amount)
{
    int dp[amount+1] = {0};
    dp[0] = 1;
    for(int i=1;i<=amount;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(coins[j]<=i)
                dp[i] += dp[i-coins[j]];
        }
    }
    cout << dp[amount];
}
int main()
{
    int n;
    cin >> n;
    int coins[n];
    for(int i=0;i<n;i++)
        cin >> coins[i];
    
    int amount;
    cin >> amount;
    
    coinChangePermutations(coins,n,amount);
}