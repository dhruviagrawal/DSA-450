#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n][3];
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin >>arr[i][j];
            
    int redCost = arr[0][0],blueCost = arr[0][1],greenCost = arr[0][2];
    
    for(int i=1;i<n;i++)
    {
        int newRedCost = arr[i][0] + min(blueCost,greenCost);
        int newBlueCost = arr[i][1] + min(redCost,greenCost);
        int newGreenCost = arr[i][2] + min(redCost,blueCost);
        
        redCost = newRedCost;
        blueCost = newBlueCost;
        greenCost = newGreenCost;
    }
    
    cout << min({redCost,blueCost,greenCost}) << endl;
}