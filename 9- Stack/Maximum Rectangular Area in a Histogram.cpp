#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long int> l(n), r(n);
        stack<long long int> stk;
        
        for(int i = 0; i < n; i++)
        {
            if(stk.empty())
            {   stk.push(i);
                l[i] = 0;
            }    
            else
            {   while(!stk.empty() && arr[i] <= arr[stk.top()])
                    stk.pop();
                l[i] = stk.empty()? 0: stk.top() + 1;
                stk.push(i);
            }
        }
        
        while(!stk.empty())
            stk.pop();
            
        for(int i = n-1; i >= 0; i--)
        {
            if(stk.empty())
            {   stk.push(i);
                r[i] = n-1;
            }    
            else
            {   while(!stk.empty() && arr[i] <= arr[stk.top()])
                    stk.pop();
                r[i] = stk.empty()? n-1: stk.top() - 1;
                stk.push(i);
            }
        }    
        
        long long int sum = 0;
        for(int i = 0; i < n; i++)
            sum = max(sum, (r[i] - l[i] + 1) * arr[i]);
        
        return sum;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends