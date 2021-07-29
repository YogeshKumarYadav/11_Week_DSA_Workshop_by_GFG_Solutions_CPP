#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int bsear(int dp[], int l, int r, int key) {
        while(l < r) {
            int m = l+(r-l)/2;
            if(key <= dp[m])
                r = m;
            else
                l = m + 1;
        }
        return r;
    }
    
    int longestSubsequence(int n, int a[]) {
        int dp[n];
        dp[0] = a[0];
        int len = 1;
        for(int i=1; i<n; i++) {
            if(a[i] < dp[0])
                dp[0] = a[i];
            else if(a[i] > dp[len-1])
                dp[len++] = a[i];
            else
                dp[bsear(dp, 0, len-1, a[i])] = a[i];
        }
        
        return len;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends