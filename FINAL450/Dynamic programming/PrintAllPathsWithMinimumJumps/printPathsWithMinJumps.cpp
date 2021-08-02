#include<bits/stdc++.h>
#define int long long
using namespace std;

void printPaths(int currIndex,int stepsAllowed,int jumpsRemaining,string psf,int n,int dp[],int arr[])
{
    if(jumpsRemaining==0){
        cout << psf.substr(0,psf.size()-4) + " ."<< endl;
        return;
    }
    for(int j=1;j<=stepsAllowed && (currIndex+j)<n;j++)
    {
        if(dp[currIndex+j]==dp[currIndex]-1)
            printPaths(currIndex+j,arr[currIndex+j],jumpsRemaining-1,psf+to_string(currIndex+j)+" -> ",n,dp,arr);
    }
}

//class ISJP for storing the relevant data while printing paths using BFS using queue
class ISJP{
public : 
  int i;
  int s;
  int j;
  string psf;
  ISJP(int i,int s,int j,string psf){
      this->i = i;
      this->s = s;
      this->j = j;
      this->psf = psf;
  }
};
void minJumps(int arr[],int n)
{
    int dp[n] = {0};
    dp[n-1] = 0;
    
    for(int i=n-2;i>=0;i--)
    {
        int mn = INT_MAX;
        for(int j=1;j<=arr[i]&&(j+i)<n;j++)
        {
            mn = min(mn,dp[i+j]);
        }
        dp[i] = (mn!=INT_MAX) + mn;
    }
    
    cout << dp[0] << endl;
    
    //printing all paths 
    //arguments are :-
    //current index, steps we can take further from current index, jumps remaining,path so     //far, and the size of array as we can't move outside that along with dp array and         //steps array
    //printPaths(0,arr[0],dp[0],"0 -> ",n,dp,arr);
    
    //above technique was DFS, now we will use bfs for the path printing

    queue<ISJP>q;
    q.push(ISJP(0,arr[0],dp[0],"0 -> "));
    
    while(!q.empty())
    {
        ISJP isjp = q.front();
        q.pop();
        
        int currIndex = isjp.i;
        int steps = isjp.s;
        int jumps = isjp.j;
        string psf  = isjp.psf;
        
        
        if(jumps==0){
            cout << psf.substr(0,psf.size()-4) + " ." <<endl;
        }
        for(int j=1;j<=steps && (currIndex+j)<n;j++)
        {
            if(dp[currIndex+j]==dp[currIndex]-1)
                q.push(ISJP(currIndex+j,arr[currIndex+j],dp[currIndex+j],psf+to_string(currIndex+j)+" -> "));
        }
    }
   
   
}
int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    minJumps(arr,n);
}