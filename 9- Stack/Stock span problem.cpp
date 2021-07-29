#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends




class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
        stack<int> stk;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
        {
            if(stk.empty())
            {   stk.push(i);
                v[i] = 1;
            }
            else
            {   while(!stk.empty() && arr[i] >= arr[stk.top()])
                    stk.pop();
                v[i] = stk.empty()? (i + 1): (i - stk.top()); 
                stk.push(i);
            }
            
        }
        return v;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends