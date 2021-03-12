#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string reverseWord(string str)
{
  int l=str.length();
  string str2;
  int i=0;
  for (int i = l-1; i >=0; i--)
  {
  	// str2.push_back(str[i]);
  	str2+=str[i];
  }

  return str2;
}

void reverseArray(int a[],int size)
{
	int temp;
	for (int i = 0, j=size-1; i<j;i++,j--)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}

}

int main()
{
	string str;
	cin>>str;
	cout<<reverseWord(str)<<endl;

	int a[]={1,2,3,4,5,6};
	int m=sizeof(a)/sizeof(a[0]);
	reverseArray(a,m);
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
	{
		cout<<a[i]<<" ";
	}
	

	return 0;
}