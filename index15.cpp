#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=5Du2iSRrbEw  ( URL for explanation of this strategy)

int minJumps(int a[], int n)
{
	//2 3 1 1 2 4 2 0 1 1

	int stepsRemaining,maxReachable,jumps;
	stepsRemaining=a[0];
	maxReachable=a[0];
	jumps=1;
	int i=0;
	while(i<n)
	{
		maxReachable=max(maxReachable,a[i]+i);//this denotes what maximum index can we reach
		// cout<<i<<"I ";
		// cout<<maxReachable<<"M ";
		if(maxReachable==i)//this means we landed on a element which is 0 and thus we cant move any further, eg {1, 0, 5, 8}
			return -1;
		// cout<<stepsRemaining<<"S ";
		if(stepsRemaining==0&&i!=n-1)// second condition is beacuse we dont want to increment 
		{							 // jump value in case we have reached the end and steps left are zero
			jumps++;				 // coz we dont need to move any forward now. 
			stepsRemaining=maxReachable-i;
		}
		// cout<<jumps<<"J ";
		// cout<<endl;
		i++;
		stepsRemaining--;
	}
    
    return jumps;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	
	cout<<minJumps(a,n);
}


// another approach(gave TLE error)

// int minJumps(int a[], int n)
// {
    
//     int jumps=0,jump_range=a[0],currently_on=0,select_this=1;
//     int max_reachable_index=currently_on+a[currently_on];

//     	if(a[currently_on]==0)
//     	{
//     	    return -1;
//     	}
//     	if(currently_on+a[currently_on]>=n-1){
//     		return 1;
//     	}

//     while((currently_on+a[currently_on])<n-1&&a[currently_on]!=0)
//     {
//     	for(int i=currently_on+1;i<=currently_on+jump_range;i++)
//     	{
//     		if(a[i]+i>max_reachable_index)
//     		{
//     			max_reachable_index=a[i]+i;
//     			select_this=i;
//     		}
//     	}
//     	currently_on=select_this;
//     	jump_range=a[currently_on];
//     	jumps++;
//     	max_reachable_index=currently_on+a[currently_on];
//     	if(currently_on+a[currently_on]>=n-1){
//     		jumps++;
//     		break;
//     	}
//     	if(a[currently_on]==0)
//     	{
//     	    return -1;
//     	}
//     }

//     return jumps;
// }
