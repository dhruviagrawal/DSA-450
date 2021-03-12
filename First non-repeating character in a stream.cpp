lass Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    int MAX_CHAR = 26;
		    int chars[MAX_CHAR] = {0};
		    char c2 = '#';
		    int count =0;
		    string res="";
		    queue<char>q;
	        for(char c: A)
	        {
	           // m[c]++;
	            q.push(c);
	            chars[c-'a']++;
	            while(!q.empty())
	            {
	                if(chars[q.front()-'a']>1)
	                q.pop();
	                else
	                {
	                    res+=q.front();
	                    break;
	                }
	            }
	            if(q.empty())
	            res+='#';
	        }
		    return res;
		}

};
