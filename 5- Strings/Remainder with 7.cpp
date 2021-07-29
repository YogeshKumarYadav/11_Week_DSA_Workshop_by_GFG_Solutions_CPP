#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method */
    int remainderWith7(string str)
    {   int n=str.length();
        int i=0;
        int no=0;
        while(i<n)
        {
            no=(no*10)+(int)(str[i]-'0');
            no=no%7;
            i++;
        }
        return no;
    }
};

// { Driver Code Starts.
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--)
    {
    string n;
    cin>>n;
    Solution ob;
    cout<<ob.remainderWith7(n)<<endl;
    
    }
	return 0;
}  // } Driver Code Ends