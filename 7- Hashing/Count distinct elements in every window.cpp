#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 0; i < k; i++)
            mp[arr[i]]++;
        
        ans.push_back(mp.size());
        for(int i=k; i<n; i++)
        {   if(--mp[arr[i-k]] == 0)
                mp.erase(arr[i-k]);
            mp[arr[i]]++;
            ans.push_back(mp.size());
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends