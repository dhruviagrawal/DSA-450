class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s,s2;
        int n=heights.size();
        int area= -1;
        vector<int>l(n),r(n);
        for(int i=0;i<n;i++)
        {
            if(s.empty()) {s.push(i); l[i] = 0;}
            else
            {
                while(!s.empty() and heights[s.top()]>=heights[i])
                {
                    s.pop();
                }
             if(!s.empty())
                 l[i] = s.top() + 1;
                else
                    l[i] = 0;
                s.push(i);
            }
        }
        
    for(int i=n-1;i>=0;i--)
        {
            if(s2.empty()) {s2.push(i); r[i] = n-1;}
            else
            {
                while(!s2.empty() and heights[s2.top()]>=heights[i])
                {
                    s2.pop();
                }
             if(!s2.empty())
                 r[i] = s2.top() - 1;
                else
                    r[i] = n-1;
                s2.push(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            area = max(area,(r[i]-l[i]+1)*heights[i]);
        }
        return area;
    }
};
