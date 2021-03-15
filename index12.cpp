
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void rotate(int a[], int n)
{
    int temp;
    int last =a[n-1];
    for (int i = n-1; i >=1; i--)
   		a[i]=a[i-1];
   	a[0]=last;
    
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int k=0;k<n;k++)
		cin>>a[k];
	rotate(a,n);
	for(int k=0;k<n;k++)
		cout<<a[k]<<" ";
}