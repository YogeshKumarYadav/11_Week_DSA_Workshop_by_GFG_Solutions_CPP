#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int eggDrop(int e, int f) {
        int dp[e+1][f+1];
        
        for(int i=0; i<=e; i++)
            dp[i][0] = 0;
        for(int j=0; j<=f; j++)
            dp[0][j] = 0;    
        
        for(int i=1; i<=e; i++)
            dp[i][1] = 1;
        for(int j=2; j<=f; j++)
            dp[1][j] = j;
            
        for(int i=2; i<=e; i++) {
            for(int j=2; j<=f; j++) {
                int temp, val = INT_MAX;
                for(int l=0, r=j-1; l<=r; l++, r--){
                    temp = max(dp[i-1][l], dp[i][r]) + 1;
                    val = min(val, temp);
                }
                dp[i][j] = val;
            }
        }
        return dp[e][f];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code EndsS