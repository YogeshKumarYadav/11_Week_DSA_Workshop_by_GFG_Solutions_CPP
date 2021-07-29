#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool check(vector<int> adj[], int node, vector<bool> &v_start, vector<bool> &v_sub)
	{
	    v_sub[node] = true;
	    for(int i: adj[node])
	        if(v_start[i] == false)
	            if(v_sub[i] || check(adj, i, v_start, v_sub))
	                return true;
	                
	    v_start[node] = true;
	    v_sub[node] = false;
	    return false;
	} 
	
	bool isCyclic(int v, vector<int> adj[]) 
	{   
	    vector<bool> v_start(v, false), v_sub(v, false);
	   	for(int i=0; i<v; i++)
	   	    if(v_start[i] == false)
	   	        if(check(adj, i, v_start, v_sub))
	   	            return true;
	   	
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends