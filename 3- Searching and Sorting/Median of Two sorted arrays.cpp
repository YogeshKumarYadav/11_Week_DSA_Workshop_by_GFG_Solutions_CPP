//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the median of the two arrays when they get merged.
    int findMedian(int arr[], int n, int brr[], int m)
    {   int i=n-1,j=0;
        while(i>=0 && j<m)
        {   if(arr[i]>brr[j])
                swap(arr[i],brr[j]);
            i--;
            j++;
        }
        sort(arr,arr+n);
        sort(brr,brr+m);
        int mid=(m+n)/2;
        if((m+n)%2==0)
        {   if(mid<n)
                return (arr[mid-1]+arr[mid])/2;   
            if(mid==n)
                return (arr[mid-1]+brr[0])/2;
            if(mid>n)
                return (brr[mid-1-n]+brr[mid-n])/2;
        }
        else
        {   if(mid<n)
                return (arr[mid]);   
            if(mid>=n)
                return (brr[mid-n]);
        } 
    }

};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int arr[n];
	    int brr[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> brr[i];
	    }
	    Solution obj;
	    if(n < m)
	        cout << obj.findMedian(arr, n, brr, m) << endl;
	   else
	        cout << obj.findMedian(brr, m, arr, n) << endl;
	    
	}

}  // } Driver Code Ends