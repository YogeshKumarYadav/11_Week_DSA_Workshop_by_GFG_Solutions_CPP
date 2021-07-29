#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int getmaxsum(vector<int> v, int m) {
        vector<int> l(m), r(m);
        stack<int> stk;
        for(int i=0; i<m; i++) {
            if(stk.empty())
                l[i] = 0;
            else {
                while(!stk.empty() && v[i] <= v[stk.top()])
                    stk.pop();
                l[i] = stk.empty()? 0: stk.top() + 1;    
            }
            stk.push(i);
        }
        while(!stk.empty())
            stk.pop();
        for(int i=m-1; i>=0; i--) {
            if(stk.empty())
                r[i] = m-1;
            else {
                while(!stk.empty() && v[i] <= v[stk.top()])
                    stk.pop();
                r[i] = stk.empty()? m - 1: stk.top() - 1;    
            }
            stk.push(i);
        }
        int ans = 0;
        for(int i=0; i<m; i++) {
            ans = max((r[i] - l[i] + 1) * v[i], ans);
        }
        return ans;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> v;
        for(int i=0; i<m; i++)
            v.push_back(M[0][i]);
        
        int maxsum = getmaxsum(v, m);
        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++)
                if(M[i][j])
                    v[j] += 1;
                else
                    v[j] = 0;
            maxsum = max(maxsum, getmaxsum(v, m));
        }
        return maxsum;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends