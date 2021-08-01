//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int highbit (int n)
    {
        int i = 0;
        while (n) {
            i++;
            n = n >> 1;
        }
        
        return i-1;
    }
    
    int countSetBits (int n)
    {   if (n == 0)
            return 0;
        int bit = highbit (n), base = 2, cpy;
        int count = (1 << (bit - 1)) * bit;
        int remain = n - (1 << bit) + 1;
        return count + remain + countSetBits(n - (1 << bit));
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends