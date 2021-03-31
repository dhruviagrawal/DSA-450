#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<string>ans;
bool isPalindrome(string &s)
{
    int n = s.size();
    for(int i=0;i<n/2;i++)
        if(s[i]!=s[n-i-1])
            return false;
    return true;
}
void palindromicPartitions(string s,string osf)
{
    if(s.size()==0)
    {
        ans.push_back(osf);
        return;
    }
    for(int i=0;i<s.size();i++)
    {
        string left = s.substr(0,i+1);
        if(isPalindrome(left))
        {
            string right = s.substr(i+1,s.size()-i-1);
            palindromicPartitions(right,osf+left+" ");
        }
    }
}
void solve()
{
    string s;
    cin >> s;
    palindromicPartitions(s,"");
    for(auto str:ans)
    {
        cout << str << endl;
    }

}
int32_t main()
{
    int t = 1;
    cin >> t;
    while(t--)
    solve();
}