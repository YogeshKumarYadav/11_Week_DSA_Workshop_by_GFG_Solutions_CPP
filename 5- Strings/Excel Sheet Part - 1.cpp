//Initial template for C++


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    string ExcelColumn(int n)
    {   int r;
        string s = "";
        while (n > 0)
        {
            r = n % 26;
            n /= 26;
            if (r==0)
            {
                s+='Z';
                n--;
            }
            else
                s+=char(r+64);
        }
        reverse (s.begin(), s.end());
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.ExcelColumn(n)<<endl;
    }
    return 0;
}
      // } Driver Code Ends