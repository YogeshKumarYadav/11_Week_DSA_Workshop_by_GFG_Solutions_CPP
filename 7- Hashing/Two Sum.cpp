// Initial function template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
// User function template for C++

// A[] : the input array of positive integers
// N : size of the array arr[]
// X : the required sum
class Solution
{
    public:
    bool keypair(vector<int> a, int n, int x)
    {
        unordered_map<int, int> mp;
        int sum = 0;
        for(int i = 0; i < n; i++)
            if(mp.find(x - a[i]) != mp.end())
                return true;
            else
                mp[a[i]] = x - a[i];
        return false;        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> array(n);
        Solution ob;
        
        for (int i = 0; i < n; i++) cin >> array[i];
            cout << (ob.keypair(array, n, x) ? "Yes" : "No") << "\n";
    }
    return 0;
}
  // } Driver Code Ends