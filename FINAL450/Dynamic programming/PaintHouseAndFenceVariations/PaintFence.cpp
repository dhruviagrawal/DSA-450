#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin >> n>>k;
    int same = k*1;
    int diff = k*(k-1);
    int total = same + diff;
    
    for(int i=3;i<=n;i++)
    {
        int newSame = diff;
        int newDiff = total * (k-1);
        
        same = newSame;
        diff = newDiff;
        total = same + diff;
    }
    
    cout << total << endl;
}