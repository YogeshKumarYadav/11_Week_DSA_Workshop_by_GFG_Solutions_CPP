//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    void fib(vector<long long> &ans, long long a, long long b, int n)
    {
        if(n == 0)
            return;
        
        ans.push_back(a+b);
        fib(ans, b, a+b, n-1);
    }
    
    vector<long long> printFibb(int n) 
    {
        vector<long long> ans;
        ans.push_back(1);
        if(n == 1)
            return ans;
        
        ans.push_back(1);
        if(n == 2)
            return ans;
            
        fib(ans, 1, 1, n-2);
        return ans;
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
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}
  // } Driver Code Ends