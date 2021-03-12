#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void rearrange(int a[], int n)
{
	//approach 1 : we can directly sort the array using standard library
	//we will display approach 2 here
	int j=0;
	int b[n];
	for (int i = 0; i < n; ++i)
		b[i]=a[i];//making another array with same elements
	for(int i=0;i<n;i++)
		if(b[i]<0)
			a[j++]=b[i];//putting negative elements at left
	for(int i=0;i<n;i++)
		if(b[i]>=0)
			a[j++]=b[i];//putting positive elements after negative elements
}


int main()
{
	int n;//size of array
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	rearrange(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}