//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


 // } Driver Code Ends
//User function template in C++


class Solution{
    public:
    
    //Function to sort an array according to the other array.
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {   
        return a.first < b.first;
    }
    
    vector<int> sortA1ByA2(vector<int> a1, int n, vector<int> a2, int m) 
    {
        unordered_map<int, int> mp;
        for(int i = 0; i < n ; i++)
            mp[a1[i]]++;
        
        vector<int> ans;  
        for(int i = 0; i < m; i++)
        {
            if(mp.find(a2[i]) != mp.end())
            {
                while(mp[a2[i]]-- > 0)
                    ans.push_back(a2[i]);
            
                if(mp[a2[i]] == 0)
                    mp.erase(a2[i]);
            }    
        }
        vector<pair<int, int>> v;
        for(auto i: mp)
            v.push_back(i);
        sort(v.begin(), v.end(), cmp);
        for(auto i : v)
        {
            while(i.second-- > 0)
                ans.push_back(i.first);
        }    
        return ans;
    } 
};

// { Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 
  // } Driver Code Ends