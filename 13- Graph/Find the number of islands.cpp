#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of islands.
    void dfs(vector<vector<char>>& grid, vector<vector<bool>> &vis, int i, int j, int n, int m)
    {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return;
        if(grid[i][j] == '0')
            return;
        if(vis[i][j] == false)
        {
            vis[i][j] = true;
            dfs(grid, vis, i+1 ,j ,n, m);
            dfs(grid, vis, i-1 ,j ,n, m);
            dfs(grid, vis, i ,j+1 ,n, m);
            dfs(grid, vis, i ,j-1 ,n, m);
            dfs(grid, vis, i+1 ,j+1 ,n, m);
            dfs(grid, vis, i-1 ,j-1 ,n, m);
            dfs(grid, vis, i+1 ,j-1 ,n, m);
            dfs(grid, vis, i-1 ,j+1 ,n, m);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(n, vector<bool>(m,false));
 
        for(int i=0; i<n; i++)
        {   for(int j=0; j<m; j++)
            {   if(vis[i][j] == false && grid[i][j] == '1')
                {   dfs(grid, vis, i ,j ,n, m);
                    count++;
                }
            }
        }
        /*     
        for(auto i: vis)
            for(auto j:i)
                cout<<j<<"  ";
        */
        return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends