#include <bits/stdc++.h>
using namespace std;
//largest sum of contiguous subarray
int main()
{
    int n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    int max=0,maxTemp=0;
    for(int i=0;i<n;i++)
    {
        maxTemp+=a[i];
        if(maxTemp<0)
        maxTemp=0; // we wont take a negative sum with us forward because this will reduce the sum of next subarray
        else if(max<maxTemp)
        max=maxTemp;
    }
    cout<<max<<endl;
}
//Time Complexity O(n)

/* Brute force-
O(n^2) Time Complexity
two loops- i=0 to n-1 and j=i to n-1
will calculate sum and keep checking
*/
