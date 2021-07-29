#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

int maxLen(int arr[], int n)
{
    unordered_map<int, int> mp;
    int ans = 0, sum = 0;
    for(int i = 0; i < n ; i++)
    {   sum += arr[i];
        
        if(sum == 0)
            ans = i + 1;
           
        if(mp.find(sum) != mp.end())
            ans = max(ans, i - mp[sum]);
        
        if(mp.find(sum) == mp.end())
            mp[sum] = i;
    }
        
    return ans;
}
