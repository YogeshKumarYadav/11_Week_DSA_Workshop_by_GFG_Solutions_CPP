#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int m, int n) 
    {
        // code here
        vector<int> v;
        int dir=0,l=0,r=n-1,u=0,d=m-1;
        while(l<=r && u<=d)
        {
            if(dir==0)
            {
                for(int i=l;i<=r;i++)
                    v.push_back(matrix[u][i]);
                u++;
            }
            else if(dir==1)
            {
                for(int i=u;i<=d;i++)
                    v.push_back(matrix[i][r]);
                r--;
            }
            else if(dir==2)
            {
                for(int i=r;i>=l;i--)
                    v.push_back(matrix[d][i]);
                d--;
            }
            else if(dir==3)
            {
                for(int i=d;i>=u;i--)
                    v.push_back(matrix[i][l]);
                l++;
            }
            dir=(dir+1)%4;
        }
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends