#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        cout<<ch;
        cout<<endl;
    }
        return 0;
}

// } Driver Code Ends


//return the address of the string
char* reverse(char *s, int len)
{
    stack<char> stk;
    for(int i = 0; i < len; i++)
        stk.push(s[i]);

    int i = 0;
    while(!stk.empty())
    {
        s[i++] = stk.top();
        stk.pop();
    }
    return s;
}