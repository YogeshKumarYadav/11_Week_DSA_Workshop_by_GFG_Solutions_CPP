#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        // Your code here
        int l=0,r=-1,i=0,sum=0;
        vector<int> ans;
        while(i<n)
        {   sum+=arr[i];
            r++;
            while(sum>s)
            {   sum-=arr[l];
                l++;
            }
            if(sum==s)
            {   ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
            i++;
        }
        if(i==n)
            return {-1};
        
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
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends