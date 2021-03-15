#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int max_sum(int a[], int n)
{
	int current_max=0, overall_max=INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		current_max=current_max+a[i];
		if(current_max<a[i])
			current_max=a[i];
		if(overall_max<current_max)
			overall_max=current_max;
	}
	return overall_max;

}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<max_sum(a,n);
}