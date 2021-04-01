#include<bits/stdc++.h>
#define int long long
using namespace std;
bool isPalindrome(string &s)
{
    int n = s.size();
    for(int i=0;i<n/2;i++)
        if(s[i]!=s[n-i-1])
            return false;
    return true;
}
int palindromePartitioning(string s)
{
    int dp[s.size()] = {0};
    for(int i=0;i<s.size();i++)
    {
        dp[i] = INT_MAX;
        for(int j=0;j<=i;j++)
        {
            string suffix = s.substr(j,i-j+1);
            if(isPalindrome(suffix))
            {
                if(j==0){
                    dp[i] = 0;
                }
                dp[i] = min(dp[i],1+dp[j-1]);
                //cout << dp[i] << endl;
            }
        }
     }
     return dp[s.size()-1];
}
void solve()
{
    string s;
    cin >> s;
    cout << palindromePartitioning(s) << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while(t--)
    solve();
}