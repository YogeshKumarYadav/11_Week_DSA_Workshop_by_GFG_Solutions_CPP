#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        long long cost = 0;
        priority_queue<long long, vector<long long>, greater<long long>> q;
        for(long long i=0; i<n; i++)
           q.push(arr[i]);
        
        while(q.size() > 1)
        {
            long long sum = q.top();
            q.pop();
            sum += q.top();
            q.pop();
            cost += sum;
            q.push(sum);
        }
        q.pop();
        
        return cost;
    }
};


// { Driver Code Starts.
long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends