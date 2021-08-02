#include<bits/stdc++.h>
using namespace std;

bool isSafe(int mat[101][101],int col[],int c,int v,int V)
{
    for(int i=0;i<V;i++)
    {
        if(mat[v][i]==1 && col[i]==c)
            return false;
    }
    return true;
}
bool solve(int mat[101][101],int m,int col[],int v,int V)
{
    if(v>=V)
        return true;
    //check for all the possibilities of assigning a color
    for(int c = 1;c<=m;c++)
    {
        if(isSafe(mat,col,c,v,V))
        {
            col[v] = c;
            if(solve(mat,m,col,v+1,V))
                return true;
           	col[v] = 0;
        }
    }
    return false;
}

int graphColoring(int graph[101][101],int m,int n) {
    // Write your code here
    int col[n] = {0};
    if(solve(graph,m,col,0,n))
   	 return 1;
    else
        return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int i;
        int graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < n; i++) {
           for(int j=0;j<n;j++)
            cin >> graph[i][j];
        }
        cout << (graphColoring(graph, m, n)==1 ?"YES":"NO")<< endl;
    }
    return 0;
}
  // } Driver Code Ends