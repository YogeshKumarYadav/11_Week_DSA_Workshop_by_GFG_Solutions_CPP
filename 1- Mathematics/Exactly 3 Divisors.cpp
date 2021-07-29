//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int isprime(int n)
    {   
        for(int i=2;i*i<=n;i++)
            if(n%i==0)
                return 0;
        return 1;
    }
    
    int exactly3Divisors(int n)
    {
        //Your code here
        int count=0;    
        for(int i=2;i*i<=n;i++)
            if(isprime(i))
                count++;
        
        return count;
    }
};

// { Driver Code Starts.


int main()
 {
    int T;
    
    //taking testcases
    cin>>T;
    while(T--)
    {
        int N;
        
        //taking N
        cin>>N;
        Solution ob;
        //calling function exactly3Divisors()
        cout<<ob.exactly3Divisors(N)<<endl;
    }
	return 0;
}  // } Driver Code Ends