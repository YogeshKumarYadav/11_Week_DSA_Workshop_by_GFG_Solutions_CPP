#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);
        
        int ans = 0;    
        for(auto i : mp)
        {   vector<int> temp(i.second);
            ans = max(ans, temp[temp.size()-1] - temp[0]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends