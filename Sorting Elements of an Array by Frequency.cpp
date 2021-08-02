class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    bool static cmp(pair<int, int>& a, 
         pair<int, int>& b) 
{ 
    if (a.second==b.second)
    return a.first>b.first;
    return a.second < b.second; 
} 
    vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here
        map<int,int,greater<int>>M;
        for(int i=0;i<n;i++)
        M[arr[i]]++;
        vector<pair<int, int> > A; 
  
    // Copy key-value pair from Map 
    // to vector of pairs 
    for (auto& it : M) { 
        A.push_back(it); 
    } 
  
    // Sort using comparator function 
    sort(A.begin(), A.end(), cmp); 
   vector<int>v;
   for(auto i: A)
   {
       for(int j=0;j<i.second;j++)
       v.push_back(i.first);
   }
   reverse(v.begin(),v.end());
   return v;
    }
};
