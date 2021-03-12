#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int a[], int n, int k) 
{
    sort(a,a+n);
    return a[k-1];    
}

int main()
{
	int n,k;//n is size of array, k is for kth smallest element
	cin>>n>>k;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	cout<<kthSmallest(a,n,k);
}