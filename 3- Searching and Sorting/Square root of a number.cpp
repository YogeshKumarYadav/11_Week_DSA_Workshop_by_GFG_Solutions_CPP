//Initial Template for C

#include<stdio.h>
  

 // } Driver Code Ends
//User function Template for C

long long int floorSqrt(long long int x) 
{
    // Your code goes here   
    if(x==0)
       return 0;
    long long int l=1,r=x,m,sol=0;
    while(l<=r)
    {
        m=l+(r-l)/2;
        if(m <= x/m)
        {   sol=m; 
            l=m+1;
        }
        else
            r=m-1;
    }
    return sol;
}

// { Driver Code Starts.

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long n;
		scanf("%ld", &n);
	
		printf("%ld\n", floorSqrt(n));
	}
    return 0;   
}
  // } Driver Code Ends