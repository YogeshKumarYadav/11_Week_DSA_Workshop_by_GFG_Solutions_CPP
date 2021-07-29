// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        // code here
        long long int mod=100000007;
        int d;
        int p,q;
        d=(b*b)-(4*a*c);
        if(d<0)
            return {-1};
        
        else
        {   p=(floor)((-1*b-sqrt(d))/(2*a));
            q=(floor)((-1*b+sqrt(d))/(2*a));
            if(q>p)
                return {q,p};
            else
                return {p,q};
        }
    }
};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        Solution ob;
        vector<int> roots = ob.quadraticRoots(a, b, c);
        if (roots.size() == 1 && roots[0] == -1)
            cout << "Imaginary";
        else
            for (int i = 0; i < roots.size(); i++) cout << roots[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends