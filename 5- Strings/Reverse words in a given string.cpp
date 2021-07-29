#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    void rever(string &str, int l, int r)
    {
        while(l<r)
        {
            swap(str[l],str[r]);
            l++;
            r--;
        }
    }
    
    string reverseWords(string s) 
    { 
        // code here
        int i=0,count,n=s.length();
        vector<int> v;
        for(int i=0;i<n;i++)
            if(s[i]=='.')
                v.push_back(i);
        v.push_back(n);        
        int l=0;        
        for(int i=0;i<v.size();i++)
        {   rever(s,l,v[i]-1);
            l=v[i]+1;
        }
        rever(s,0,n-1);
        return s;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends