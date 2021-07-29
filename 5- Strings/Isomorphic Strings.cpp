// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        if(str1.length()!=str2.length())
            return false;
            
        int n=str1.length();    
        /*
        map<char,char> mp;
        set<char> s;
        for(int i=0;i<n;i++)
        {
            if(mp.count(str1[i])==0 && s.count(str2[i])==0)
            {
                mp[str1[i]]=str2[i];
                s.insert(str2[i]);
            }    
            else if(mp.count(str1[i])==0 && s.count(str2[i])!=0)
                return false;
            else if(mp[str1[i]]!=str2[i])
                return false;
        }   
        return true;
        Execution Time:0.22
        */
        
        bool arr[256]={false};
        int rem[256]={-1};
        memset(rem,-1,sizeof(rem));
        for(int i=0;i<n;i++)
        {
            if(rem[str1[i]]==-1)
            {
                if(arr[str2[i]]==true)
                    return false;
                arr[str2[i]]=true;
                rem[str1[i]]=str2[i];
            }
            else if(rem[str1[i]]!=str2[i])
                return false;
        }
        return true;

        
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends