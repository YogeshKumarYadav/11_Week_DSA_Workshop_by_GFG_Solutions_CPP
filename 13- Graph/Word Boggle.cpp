// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &vis, string str, int i, int j, int index)
    {
        if(index == str.size())
            return true;
        if(i >= 0 && j >= 0 && i < board.size() && j < board[0].size() && vis[i][j] == false && board[i][j] == str[index])
        {
            vis[i][j] = true;
            if( dfs(board, vis, str, i+1, j, index + 1) ||
                dfs(board, vis, str, i-1, j, index + 1) ||
                dfs(board, vis, str, i, j+1, index + 1) ||
                dfs(board, vis, str, i, j-1, index + 1) ||
                dfs(board, vis, str, i+1, j+1, index + 1) ||
                dfs(board, vis, str, i-1, j-1, index + 1) ||
                dfs(board, vis, str, i+1, j-1, index + 1) ||
                dfs(board, vis, str, i-1, j+1, index + 1) )
                    return true;
            vis[i][j] = false;        
        }
        return false;
    }

    bool check(vector<vector<char>> &board, string str)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(str[0] == board[i][j])
                    if(dfs(board, vis, str, i ,j, 0))
                        return true;
        return false;                
    }

	vector<string> wordBoggle(vector<vector<char>> &board, vector<string>& dictionary)
	{
	    vector<string> ans;
	    for(string str: dictionary)
	    {   if(check(board, str) == true)
	            ans.push_back(str);
	    }
	    return ans;      
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends