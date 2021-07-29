#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to return kth largest element from an array.
    int KthLargest(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0; i<k; i++)
            q.push(arr[i]);
        
        for(int i=k; i<n; i++)
        {
            if(arr[i] >= q.top())
            {   q.pop();
                q.push(arr[i]);
            }
        }
        return q.top();    
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.KthLargest(arr, n, k) << endl;
    }

    return 0;
}  // } Driver Code Ends