// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to convert an infix expression to a postfix expression.
    int priority(char ch)
    {
        if(ch == '^')
            return 3;
        else if(ch == '*' || ch == '/')
            return 2;
        else if(ch == '+' || ch == '-')
            return 1;
        else
            return -1;
    }
    string infixToPostfix(string s)
    {
        stack<char> stk;
        string ans = "";
        for(int i = 0; i < s.length(); i++)
        {   
            if(isalnum(s[i]))
                ans += s[i];
                
            else if(s[i] == '(')
                stk.push('(');    
            
            else if(s[i] == ')')
            {   while(!stk.empty() && stk.top() != '(')
                {   ans += stk.top();
                    stk.pop();
                }
                stk.pop();
            }             
            
            else
            {   while(!stk.empty() && priority(s[i]) <= priority(stk.top()))
                {   ans += stk.top();
                    stk.pop();
                }    
                stk.push(s[i]);
            }
        }
        
        while(!stk.empty())
        {   ans += stk.top();
            stk.pop();
        }
        
        return ans;
    }
};


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
        Solution ob;
        cout<<ob.infixToPostfix(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends