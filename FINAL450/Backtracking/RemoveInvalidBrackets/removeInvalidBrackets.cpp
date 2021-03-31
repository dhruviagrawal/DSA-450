#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string>sol;
    int getMin(string s)
    {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')st.push(s[i]);
            else if(s[i]==')')
            {
                if(!st.empty() && st.top()=='(')st.pop();
                else st.push(s[i]);
            }
        }
        return st.size();
    }
    void solve(string s,int removalsLeft,set<string>&ans)
    {
        if(removalsLeft==0)
        {
            //check if further removals are required to make the string balanced or nor
            int removalsRequired = getMin(s);
            if(removalsRequired==0){
                 if(ans.find(s)==ans.end())
                 {
                    ans.insert(s);
                    sol.push_back(s);
                 }
            }
            return;
        }
            for(int i=0;i<s.size();i++)
            {
                string left = s.substr(0,i);
                string right = s.substr(i+1,s.size()-i-1);
                solve(left+right,removalsLeft-1,ans);
            }
        }
    vector<string> removeInvalidParentheses(string s) {
        sol.clear();
        //first get the minimum no  of removals
        int minRemovals = getMin(s);
        set<string>ans;
        solve(s,minRemovals,ans);
        return sol;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution obj;
    vector<string>ans = obj.removeInvalidParentheses(str);
    for(auto s:ans){
        cout << s << endl;
    }
}