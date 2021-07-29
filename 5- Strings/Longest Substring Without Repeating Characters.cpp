//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;




 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    // s is the given string
    int SubsequenceLength (string s) 
    {
        int n = s.length();
        int j = 0, ans = 0;
        vector<int> v(256,-1); 
        for (int i = 0; i < n; i++)
        {   
            j = max(j, v[s[i]]+1);
            ans = max(ans, i - j + 1);
            v[s[i]]=i;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    cin>>ws;
    while(t--)
    {
        string str;
        getline(cin,str);
        Solution obj;
        cout<<obj.SubsequenceLength(str)<<"\n";
    }
    return 0;
}
  // } Driver Code Ends