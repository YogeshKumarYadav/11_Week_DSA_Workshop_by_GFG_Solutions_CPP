// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str) {
        long long int mod = 1000000007;
        int n = str.length();
        long long int dp[n+1][n+1];
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                dp[i][j] = (i == j && i != 0)? 1: 0;
    
        for(int k=2; k<=n; k++) {
            for(int i=1, j=k; i<=n && j<=n; i++, j++) {
                if(str[i-1] == str[j-1])
                    dp[i][j] = (dp[i][j-1]%mod + dp[i+1][j]%mod + 1)%mod;
                else
                    dp[i][j] = (dp[i][j-1]%mod + dp[i+1][j]%mod - dp[i+1][j-1]%mod)%mod;
                
                if(dp[i][j] < 0) 
                    dp[i][j] += mod;
            }
        }
        
        return dp[1][n]%mod;    
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends