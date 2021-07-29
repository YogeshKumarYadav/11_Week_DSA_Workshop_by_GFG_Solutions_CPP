#include<bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends

class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
        if(s1=="0"||s2=="0")
            return to_string(0);
        
        int sign=1;
        if(s1[0]=='-')
        {
            sign*=-1;
            s1.erase(0,1);
        }
        if(s2[0]=='-')
        {
            sign*=-1;
            s2.erase(0,1);
        }
        int k = s1.length() + s2.length();
        int a[k] = {0};
        int digit;
        for (int i = s1.length() - 1; i >= 0; i--)
        {
            for (int j = s2.length() - 1; j >= 0; j--)
            {   
                digit = (s1[i] - '0') * (s2[j] - '0');
                a[j + i + 1] += digit;
                a[i + j] += a[i + j + 1] / 10;
                a[i + j + 1] = a[j + i + 1] % 10;
                //cout<<a[i+j]<<" "<<a[i+j+1]<<endl;
            }
        }
        
        string s = "";
        
        if (sign == -1)
            s = "-";
        
        int i=0;
        while(a[i]==0)
            i++;
        
        for (int j = i; j < k; j++)
            s.append(to_string(a[j]));
                
        return s;
    }

};

// { Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}  // } Driver Code Ends