#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends




//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     //Your code here
    int j,n=s.length(),m=x.length();
    for(int i=0;i<=n-m;i++)
    {
        for(j=0;j<m;j++)
            if(s[i+j]!=x[j])
                break;

        if(j==m)
            return i;
    }
    
    return -1;
     
}