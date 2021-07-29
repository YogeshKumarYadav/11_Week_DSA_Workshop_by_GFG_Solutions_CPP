
 // } Driver Code Ends


class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &vis, int i, int j, int n, int m, int &sum)
    {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return;
        if(grid[i][j] == 0)
            return;
        if(vis[i][j] == false)
        {
            vis[i][j] = true;
            sum++;
            dfs(grid, vis, i+1 ,j ,n, m, sum);
            dfs(grid, vis, i-1 ,j ,n, m, sum);
            dfs(grid, vis, i ,j+1 ,n, m, sum);
            dfs(grid, vis, i ,j-1 ,n, m, sum);
            dfs(grid, vis, i+1 ,j+1 ,n, m, sum);
            dfs(grid, vis, i-1 ,j-1 ,n, m, sum);
            dfs(grid, vis, i+1 ,j-1 ,n, m, sum);
            dfs(grid, vis, i-1 ,j+1 ,n, m, sum);
        }
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = INT_MIN;
        vector<vector<bool>> vis(n, vector<bool>(m,false));
     
        for(int i=0; i<n; i++)
        {   for(int j=0; j<m; j++)
            {   if(vis[i][j] == false && grid[i][j] == 1)
                {   int sum = 0;
                    dfs(grid, vis, i ,j ,n, m, sum);
                    count = max(count, sum);
                }
            }
        }
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
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends