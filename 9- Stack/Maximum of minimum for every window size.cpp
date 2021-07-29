#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        stack<int> stk;
        vector<int> minright(n), minleft(n);
        for(int i = n-1; i >= 0; i--)
        {
            if(stk.empty())
            {   minright[i] = n;
                stk.push(i);
            }   
            else
            {   while(!stk.empty() && arr[stk.top()] >= arr[i])
                    stk.pop();
                minright[i] = stk.empty()? n: stk.top();
                stk.push(i);
            }
        }
        
        while(!stk.empty())
            stk.pop();
            
        for(int i = 0; i < n; i++)
        {
            if(stk.empty())
            {   minleft[i] = -1;
                stk.push(i);
            }   
            else
            {   while(!stk.empty() && arr[stk.top()] >= arr[i])
                    stk.pop();
                minleft[i] = stk.empty()? -1: stk.top();
                stk.push(i);
            }
        }
        vector<int> ans(n + 1);
        for(int i = 0; i < n; i++)
        {   int j = minright[i] - minleft[i] - 1;
            ans[j] = max(ans[j], arr[i]);
        }
        for(int i = n-1; i >= 0; i--)
            ans[i] = max(ans[i], ans[i + 1]); 
        
        ans.erase(ans.begin());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends