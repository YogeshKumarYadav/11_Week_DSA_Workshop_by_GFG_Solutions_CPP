#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        if(s1.length()!=s2.length())
            return false;
            
        s1.append(s1);    
        int n=s1.length(),m=s2.length(),j;
        for(int i=0;i<n;i++)
        {   for(j=0;j<m;j++)
                if(s1[i+j]!=s2[j])
                    break;
            if(j==m)
                return true;
        }   
        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}
  // } Driver Code Ends