//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        //Complete this function
        
  /*  double gp(int adouble cr, int n)
    {
        if(n==1)
            return 1;
        return cr*gp(cr,n-1);    
    }
     */   
    double termOfGP(int a,int b,int n)
    {
        //Your code here
        if(n==1)
            return a;
        if(n==2)
            return b;
        double res=a;
        while(n>1)
        {
            res=double(res*b/a);
            n--;
        }
        return res;
        //return gp(a,b/a,n-2);
        
    }
};

// { Driver Code Starts.


int main()
{
    int T; //testcases total
    cin>>T;//input the testcases

    for(int i=0;i<T;i++) //white testcases are not exhausted
    {
        int A,B;
        cin>>A>>B; //input first and second term of gp
        int N;
        cin>>N; //input n
        Solution ob;
        cout<<floor(ob.termOfGP(A,B,N))<<endl;
    }

    return 0;
}

  // } Driver Code Ends