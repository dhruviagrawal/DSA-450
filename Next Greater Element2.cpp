typedef long long ll;
class Solution{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<ll>v,v2;
        stack<ll>s;
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            v.push_back(-1);
            else if(!s.empty() and s.top()>arr[i])
            v.push_back(s.top());
            else if(!s.empty() and s.top()<=arr[i])
        {
           while(!s.empty() and s.top()<=arr[i])
           {
               s.pop();
           }
           if(s.empty())
           v.push_back(-1);
           else v.push_back(s.top());
        }
        s.push(arr[i]);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
