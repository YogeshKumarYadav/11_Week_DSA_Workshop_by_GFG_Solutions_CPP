#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > m, int n)
    {
        // code here 
        int det=0; // the determinant value will be stored here
        if(m.size()==1)
            return m[0][0]; // no calculation needed
            
        else if(m.size()==2)
            return (m[0][0]*m[1][1]-m[0][1]*m[1][0]);
        
        else
        {
            for(int p=0;p<m[0].size();p++)
            {
                vector<vector<int>> sm;
                for (int i=1;i<m.size();i++)
                {
                    vector<int> v;
                    for (int j=0;j<m[i].size();j++)
                    {
                        if (j!=p)
                        {
                            v.push_back(m[i][j]);
                        }
                    }
                    if(v.size()>0)
                        sm.push_back(v);
                }
                det=det + m[0][p]*pow(-1,p)*determinantOfMatrix(sm,m.size());
            }
            return det;
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}  // } Driver Code Ends