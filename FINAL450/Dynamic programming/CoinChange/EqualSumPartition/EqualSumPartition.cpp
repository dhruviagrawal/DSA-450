// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
        bool subsetSum(int arr[],int N,int sum)
    {
        bool dp[N+1][sum+1];
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                //first cell
                if(i==0 && j==0){
                    dp[i][j] = true;
                }
                else if(i==0){
                    dp[i][j] = false;
                }
                else if(j==0){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                    int val = arr[i-1];
                    if(val<=j)
                        dp[i][j] |= dp[i-1][j-val];
                }
            }
        }
        return dp[N][sum];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<N;i++)
            sum += arr[i];
        if(sum&1)return 0;
        return subsetSum(arr,N,sum/2);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends