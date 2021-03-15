#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//OPTIMAL METHOD  (https://www.youtube.com/watch?v=hVl2b3bLzBw)

void merge(int a[], int b[], int n, int m) 
{
	int k=0,temp;
	int gap=ceil((m+n)/2.0);
	//cout<<gap<<endl;
	for(int i=gap;;i=ceil(i/2.0))
	{
		int indexA=0,indexB=indexA+i;
		while(indexB<m+n)
		{
		if(indexA<n&&indexB<n){
			if(a[indexA]>a[indexB])
				{temp=a[indexA];a[indexA]=a[indexB];a[indexB]=temp;indexA++;indexB++;}//swapping
			else
				{indexA++;indexB++;}
		}

		else if(indexA<n&&indexB>=n){
			if(a[indexA]>b[indexB-n])
				{temp=a[indexA];a[indexA]=b[indexB-n];b[indexB-n]=temp;indexA++;indexB++;}//swapping
			else
				{indexA++;indexB++;}
		}

		else{
			if(b[indexA-n]>b[indexB-n])
				{temp=b[indexA-n];b[indexA-n]=b[indexB-n];b[indexB-n]=temp;indexA++;indexB++;}
			else
				{indexA++;indexB++;}	
		}

		}//while loop closing
		if(i==1)
			return;
	}//for loop closing
	return;
}


int main()
{
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	merge(a,b,n,m);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	for(int i=0;i<m;i++)
		cout<<b[i]<<" ";

}

//Brute force

// void merge(int a[], int b[], int n, int m) 
// 	{
// 	    int i=0,j=0,temp;
// 	    for(j=0;j<m;j++){
// 	        i=0;
// 	    while(i<n)
// 	    {
// 	        if(a[i]>b[j])
// 	           {
// 	               temp=a[i];
// 	               a[i]=b[j];
// 	               b[j]=temp;
// 	               i++;
// 	           }
// 	       else if(a[i]<b[j])
// 	           {
// 	            i++;
// 	           }
// 	    }
	        
// 	    }
// 	    sort(b,b+m);
// 	}

//BETTER METHOD(This too gave TLE)

// void merge(int a[], int b[], int n, int m) 
// 	{
// 	    int i=0,j=0,temp;
	        
// 	    while(i<n)
// 	    {
// 	        if(a[i]>b[j])
// 	           {
// 	               temp=a[i];
// 	               a[i]=b[j];
// 	               b[j]=temp;
// 	               sort(b,b+m);
// 	           }
// 	       i++;
// 	    }
// 	}