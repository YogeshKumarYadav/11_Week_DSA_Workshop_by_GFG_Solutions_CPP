#include<bits/stdc++.h>
using namespace std;
    
vector<int> bfsOfGraph(int v, vector<int> adj[]) {
	vector<int> ans;
	vector<bool> vis(v, false);
	queue<int> q;
	
	q.push(0);
	vis[0] = true;
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for(auto i: adj[node])
			//i ->vector type
			if(vis[i] == false) {
				vis[i] = true;
				q.push(i);
			}
	}
	return ans;
}

int main() {
	int V, E;
	cin >> V >> E;

	vector<int> adj[V];
	for(int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
 		adj[v].push_back(u);
	}
	vector<int> ans = bfsOfGraph(V, adj);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
} 