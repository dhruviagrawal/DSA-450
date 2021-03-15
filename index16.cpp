#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> nums) 
    {
        int n=nums.size();
        int Frequency[n+1]={0};
        for(int i=0;i<n;i++)
        {
            if(Frequency[nums[i]]==0)
            Frequency[nums[i]]++;
            else
                return nums[i];
        }
        return -1;
    }
    
int main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<findDuplicate(v);
}