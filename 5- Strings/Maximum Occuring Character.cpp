
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends




class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    static bool cmp(pair<char,int> &a, pair<char,int> &b)
    {    return a.second>b.second;
    }
    static bool cmpi(pair<char,int> &a, pair<char,int> &b)
    {    return a.first<b.first;
    }
    
    char getMaxOccuringChar(string str)
    {
        unordered_map<char,int> mp;
        vector<pair<char,int>> v;
        int i=0;
        while(i<str.length())
        {   mp[str[i]]++;
            i++;
        }
        for(auto i:mp)
            v.push_back(i);
            
        sort(v.begin(),v.end(),cmp);
        int f=0,count=0;
        for(auto i:v)
        {   if(f>i.second)
                break;
            f=i.second;
            count++;    
        }
        v.resize(count);
        sort(v.begin(),v.end(),cmpi);
        
        return v[0].first;
    }

};

// { Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}  // } Driver Code Ends