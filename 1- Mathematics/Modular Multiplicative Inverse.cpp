//Initial Template for C++

#include<iostream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Complete this function
    int modInverse(int a, int m)
    {
        //Your code here
        int i=0;
        while(i<m)
        {
            if((i*a)%m==1)
                break;
            i++;    
        }
        if(i==m)
            return -1;
        return i;
    }
};

// { Driver Code Starts.

int main()
{
	int T;
	
	//taking testcases
	cin>>T;
	while(T--){
		int a,m;
		
		//taking input a and m
		cin>>a>>m;
		Solution ob;
		//calling function modInverse()
		cout << ob.modInverse(a, m)<<endl;
	}
    return 0;
}  // } Driver Code Ends