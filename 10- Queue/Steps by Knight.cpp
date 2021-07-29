#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&start, vector<int>&end,int n)
	{
	    if(start[0] == end[0] && start[1] == end[1])
	        return 0;
	    int board[n][n];
	    for(int i = 0; i < n; i++)
	        for(int j = 0; j < n; j++)
	            board[i][j] = 0;
	   
	    queue<pair<int, int>> q;
	    q.push(make_pair(start[0] - 1, start[1] - 1));
	    
	    while(!q.empty())
	    {   pair<int, int> cur = q.front();
	        int x = cur.first;
	        int y = cur.second;
	        q.pop();

	        if((x-1 >= 0 && x-1 < n) && (y-2 >= 0 && y-2 < n) && (board[x-1][y-2] == 0))
	        {   q.push(make_pair(x-1, y-2));
	            board[x-1][y-2] = board[x][y] + 1;
	        }
	    
	        if((x+1 >= 0 && x+1 < n) && (y-2 >= 0 && y-2 < n) && (board[x+1][y-2] == 0))
	        {   q.push(make_pair(x+1, y-2));
	            board[x+1][y-2] = board[x][y] + 1;
	        }
	        
	        if((x-2 >= 0 && x-2 < n) && (y-1 >= 0 && y-1 < n) && (board[x-2][y-1] == 0))
	        {   q.push(make_pair(x-2, y-1));
	            board[x-2][y-1] = board[x][y] + 1;
	        }
	        
	        if((x+2 >= 0 && x+2 < n) && (y-1 >= 0 && y-1 < n) && (board[x+2][y-1] == 0))
	        {   q.push(make_pair(x+2, y-1));
	            board[x+2][y-1] = board[x][y] + 1;
	        }
	        
	        if((x-2 >= 0 && x-2 < n) && (y+1 >= 0 && y+1 < n) && (board[x-2][y+1] == 0))
	        {   q.push(make_pair(x-2, y+1));
	            board[x-2][y+1] = board[x][y] + 1;
	        }
	        
	        if((x+2 >= 0 && x+2 < n) && (y+1 >= 0 && y+1 < n) && (board[x+2][y+1] == 0))
	        {   q.push(make_pair(x+2, y+1));
	            board[x+2][y+1] = board[x][y] + 1;
	        }
	        
	        if((x-1 >= 0 && x-1 < n) && (y+2 >= 0 && y+2 < n) && (board[x-1][y+2] == 0))
	        {   q.push(make_pair(x-1, y+2));
	            board[x-1][y+2] = board[x][y] + 1;
	        }
	        
	        if((x+1 >= 0 && x+1 < n) && (y+2 >= 0 && y+2 < n) && (board[x+1][y+2] == 0))
	        {   q.push(make_pair(x+1, y+2));
	            board[x+1][y+2] = board[x][y] + 1;
	        }
	    }
	    return board[end[0]-1][end[1]-1];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends