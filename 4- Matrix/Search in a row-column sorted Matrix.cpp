#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int k) 
    {
        // code here 
        
        int l=0,r=m-1;
        while(l<n && r>=0)
        {   if(matrix[l][r]==k)
                return 1;
            else if(matrix[l][r]<k)
                l++;
            else
                r--;
        }
        
        return 0;
    }
};

// { Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 

  // } Driver Code Ends