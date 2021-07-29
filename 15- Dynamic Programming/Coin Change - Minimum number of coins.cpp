    //Initial Template for C++
    
    #include <bits/stdc++.h>
    using namespace std;
    
     // } Driver Code Ends
    //Complete this function
    
    class Solution
    {
        public:
        //Function to find the minimum number of coins to make the change 
        //for value using the coins of given denominations.
        long long minimumNumberOfCoins(int coins[],int n,int v)
        {
            long long dp[n+1][v+1];
            for(int i=0; i<=n; i++)
                dp[i][0] = 0;
            for(int j=1; j<=v; j++)
                dp[0][j] = INT_MAX;
                
            for(int i=1; i<=n; i++)
                for(int j=1; j<=v; j++)
                    if(j >= coins[i-1])
                        dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
                    else
                        dp[i][j] = dp[i-1][j];
                        
            return (dp[n][v] == INT_MAX)? -1: dp[n][v];            
        }
    };
    
    // { Driver Code Starts.
    
    
    
    int main() {
    	
    	//taking total count of testcases
    	int testcases;
    	cin>>testcases;
    	while(testcases--)
    	{
    	    //taking value
    	    int value;
    	    cin>>value;
    	    
    	    //taking number of coins
    	    int numberOfCoins;
    	    cin>>numberOfCoins;
    	    int coins[numberOfCoins];
    	    
    	    //taking value of each coin
    	    for(int i=0;i<numberOfCoins;i++)
    	    cin>>coins[i];
    	    Solution obj;
    	    //calling function minimumNumberOfCoins()
    	    int answer=obj.minimumNumberOfCoins(coins,numberOfCoins,value);
    	    
    	    //printing "Not Possible" if answer is -1
    	    //else printing answer
    	    if(answer==-1)
    	    cout<<"Not Possible"<<endl;
    	    else
    	    cout<<answer<<endl;
    	    
    	}
    	return 0;
    }  // } Driver Code Ends