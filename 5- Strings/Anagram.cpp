#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    
    bool isAnagram(string a, string b){
        
        if(a.length()!=b.length())
            return false;
        
        int n=a.length();    
        int arr[26]={0};
        for(int i=0;i<n;i++)
            arr[a[i]-'a']++;
        
        for(int i=0;i<n;i++)
            arr[b[i]-'a']--;
        
        for(int i=0;i<26;i++)
            if(arr[i]!=0)
                return false;
        return true;    
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends