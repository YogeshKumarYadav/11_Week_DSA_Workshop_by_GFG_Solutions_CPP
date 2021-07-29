#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k)
    {   
        set<vector<int>> num;
        sort(arr.begin(), arr.end());
        int sum = 0;
        int n = arr.size();
        
        for(int i = 0; i < n-3; i++)
        {
            for(int j = i+1; j < n-2; j++)
            {
                int l = j+1;
                int r = n-1;
                while(l < r)
                {
                    sum = arr[i] + arr[j] + arr[l] + arr[r];
                    if(sum == k)
                    {
                        vector<int> t;
                        t.push_back(arr[i]);
                        t.push_back(arr[j]);
                        t.push_back(arr[l]);
                        t.push_back(arr[r]);
                        num.insert(t);
                        l = l + 1;
                    }
                    else if(sum > k)
                        r = r - 1;
                    else
                        l = l + 1;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto i:num)
            ans.push_back(i);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends