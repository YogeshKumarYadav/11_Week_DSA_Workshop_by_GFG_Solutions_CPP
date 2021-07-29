#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


int transitionPoint(int arr[], int n) {
        if(arr[0]==1)
        return 0;
    if(n==1 && arr[0]==0)
        return -1;
    int l=0,r=n-1,m;
    while(l<=r)
    {   m=(l+r)/2;
        if(arr[m]==1)
            if(arr[m-1]==0)
                return m;
            else
                r=m-1;
        else if(arr[m]==0)
            if(arr[m+1]==1)
                return m+1;
            else
                l=m+1;
    }
    // if(l>r)
    //     return -1;
    // else
    //     return m;
    return -1;

}