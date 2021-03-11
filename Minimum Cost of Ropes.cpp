long long minCost(long long arr[], long long n) {
    // Your code here
    priority_queue<long long,vector<long long>,greater<long long>> heap;
    long long res=0;
    for(long long i=0;i<n;i++)
    heap.push(arr[i]);
    if(heap.size()<=1)
    return 0;
    while(heap.size()>1)
    {
        long long x = heap.top(); heap.pop();
        long long y = heap.top(); heap.pop();
        res+=x+y;
        heap.push(x+y);
    }
    return res;
}
