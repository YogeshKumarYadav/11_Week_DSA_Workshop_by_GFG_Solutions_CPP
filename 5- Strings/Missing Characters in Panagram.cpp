//Initial Template for C++



#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++


class Solution{
  public:
    string missingPanagram(string strin){
    
    bool cp[26]={false};
    bool sm[26]={false};
    int i=0;
    while(i<strin.length())
    {   if(isupper(strin[i]))
            cp[strin[i]-'A']=true;
        else if(islower(strin[i]))    
            sm[strin[i]-'a']=true;
        i++;
    }
   /* 
    for(int j=0;j<26;j++)
        cout<<cp[j]<<" ";
    cout<<endl;
    for(int j=0;j<26;j++)
        cout<<sm[j]<<" ";
    cout<<endl;
    */
    bool f=true;
    for(int j=0;j<26;j++)
    {   if(cp[j]==true || sm[j]==true)
            continue;
        else
        {
            f=false;
            break;
        }
    }
    if(f==true)
        return "-1";
    string str="";
    i=0;
    while(i<26)
    {
        if(cp[i]==false && sm[i]==false)
        {
            if(i==0)
                str.push_back('a');
            else
                str.push_back('a'+i);
        }
        
        i++;
    }
    return str;
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	Solution obj;
	cout << obj.missingPanagram(s) << endl;
	}
	return 0;
	
}

  // } Driver Code Ends