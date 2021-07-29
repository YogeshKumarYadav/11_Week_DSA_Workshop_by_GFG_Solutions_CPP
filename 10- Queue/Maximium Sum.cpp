//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
  public:
    
    long maximum_sum(int n, vector<int> arr, int k)
    {
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++)
            mp[arr[i]]++;
            
        priority_queue<pair<int, int>> q;
        for(auto i : mp)
            q.push({i.second, i.first});
        
        long sum = 0;
        pair<int,int> p;
        while(k--)
        {   p = q.top();
            q.pop();
            sum += p.second;
            q.push({--p.first, p.second});
        /*
            priority_queue<pair<int, int>> a = q;
            while(!a.empty())
            {   pair<int, int> t = a.top();
                cout<<t.first<<" "<<t.second<<"   ";
                a.pop();
            }
            cout<<endl;
        */
        } 
        return sum;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>v(n,0);
        
        for(int i=0;i<n;i++)
        cin>>v[i];
        Solution obj;
        cout<< obj.maximum_sum(n,v,k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends