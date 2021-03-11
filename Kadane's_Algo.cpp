//this is used for maximum contiguous subarray sum problem

#include <bits/stdc++.h>
/*The simple logic is to use to look for all positive contiguous segments of the array(maxending here is used for this) 
, while maxsofar is used for storing the max value from all the subarray so far*/
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}