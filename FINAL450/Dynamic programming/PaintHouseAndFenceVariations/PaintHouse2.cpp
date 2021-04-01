#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    int arr[n][k];
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            cin >> arr[i][j];
            
    int dp[k][n];
    //intialising the first column
    for(int i=0;i<k;i++)
        dp[i][0] = arr[0][i];
        
    for(int j=1;j<n;j++)
    {
       
        for(int i=0;i<k;i++)
        {
             int mn = INT_MAX;
            for(int l=0;l<k;l++)
            if(l!=i)
                mn = min(mn,dp[l][j-1]);
                
            dp[i][j] = arr[j][i] + mn;
        }
    }
    
    int mn = INT_MAX;
    for(int i=0;i<k;i++)
        mn = min(mn,dp[i][n-1]);
        
    cout << mn << endl;
}