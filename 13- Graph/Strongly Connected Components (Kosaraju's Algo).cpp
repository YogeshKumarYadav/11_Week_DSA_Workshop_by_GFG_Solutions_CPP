#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node, vector<bool> &vis, stack<int> &stk, vector<int> adj[])
	{   vis[node] = true;
	    for(auto i: adj[node])
	        if(vis[i] == false)
	            dfs(i, vis, stk, adj);
	    stk.push(node);         
	}
	
	void dfs2(vector<int> rev[], int node, vector<bool> &vis)
	{   vis[node] = true;
	    for(auto i: rev[node])
	        if(vis[i] == false)
	            dfs2(rev, i, vis);
	}
	
    int kosaraju(int v, vector<int> adj[])
    {   stack<int> stk;
        vector<bool> vis(v,false);
        for(int i=0; i<v; i++)
            if(vis[i] == false)
                dfs(i, vis, stk, adj);
                
        vector<int> rev[v];        
        for(int i=0; i<v; i++)
	        for(auto j: adj[i])
	            rev[j].push_back(i);
	            
        vector<bool> vis2(v, false);
        int count = 0;
        while(!stk.empty())
        {   int node = stk.top();
            stk.pop();
            if(vis2[node] == false)
            {   dfs2(rev, node, vis2);
                count++;
            }
        }
        return count;
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
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends