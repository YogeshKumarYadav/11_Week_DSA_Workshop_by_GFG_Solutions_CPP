#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string ip) {
            int len  = ip.length();
            int count = 0 ;

            for(int i=0;i<len;i++)
            if(ip[i]=='.')
                count++;
            if(count!=3)
                return false;
            
            string s="";
            bool flag=true;
            bool zero=false;
            for(int i=0;i<len;i++)
            {
                if(ip[i]=='.')
                {
                    if(flag)
                        return false;
                    if(zero)
                        zero=false;
                    if(flag==false)
                        flag = true;
                    stringstream g(s);
                    int temp ;
                    g>>temp;
                    
                    if(temp>255)
                    return false;
                    s="";
                }
                else
                {
                    if(isdigit(ip[i])==false)
                        return false;
                    if(zero)
                        return false;
                    if(flag)
                    {   if(ip[i]=='0')
                            zero  = true;
                        flag=false;
                    }
                    s += ip[i];
                }
            }
            stringstream g(s);
            int temp ;
            g>>temp;
                    
            return temp<256;

        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends