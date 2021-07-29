//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    
    long long gcd(long int a, long long b)
    {
        if(b==0)
            return a;
        return gcd(b,a%b);   
    }

    long long getSmallestDivNum(long long n){
        // code here
        
        long long a=1;
        for(long long i=2;i<n+1;i++)
            a=(a*i)/gcd(a,i);
            
        return a;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<< ob.getSmallestDivNum(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends