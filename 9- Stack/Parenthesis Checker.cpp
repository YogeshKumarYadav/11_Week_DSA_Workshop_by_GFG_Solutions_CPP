#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        stack<char> stk;
        for(int i = 0; i < s.length(); i++)
        {   
            if(stk.empty())
                stk.push(s[i]);
                
            else if(s[i] == ']')
                if(stk.top() == '[')
                    stk.pop();
                else
                    return false;
                    
            else if(s[i] == '}')
                if(stk.top() == '{')
                    stk.pop();
                else
                    return false;
                    
            else if(s[i] == ')')
                if(stk.top() == '(')
                    stk.pop();
                else
                    return false;
            
            else
                stk.push(s[i]);
        }
        if(stk.empty() == true)
            return true;
        else
            return false;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends