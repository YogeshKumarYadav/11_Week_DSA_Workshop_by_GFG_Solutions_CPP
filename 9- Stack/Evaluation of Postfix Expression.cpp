
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {   stack<int> stk;
        for(int i = 0; i < s.length(); i++)
        {
            if(isdigit(s[i]))
                stk.push((int)(s[i] - '0'));
            else
            {   int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                switch(s[i])
                {
                    case '+': stk.push(a + b);
                    break;
                    case '-': stk.push(a - b);
                    break;
                    case '*': stk.push(a * b);
                    break;
                    case '/': stk.push(a / b);
                    break;
                }
            }
        }
        return stk.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends