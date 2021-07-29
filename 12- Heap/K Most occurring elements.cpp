#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
// Function to print the k numbers with most occurrences 

class Solution
{
    public:
    //Function to return the sum of frequencies of k numbers
    //with most occurrences in an array.
    int kMostFrequent(int arr[], int n, int k) 
    { 
    	unordered_map<int, int> mp;
    	for(int i=0; i<n; i++)
    	    mp[arr[i]]++;
    	
    	priority_queue<int> q;
    	for(auto i: mp)
    	    q.push(i.second);
    	
    	int sum = 0;
    	for(int i=0; i<k; i++)
    	{   sum += q.top();
    	    q.pop();
    	}
    	return sum;
    } 
};

// { Driver Code Starts.
// Driver program to test above 
int main() 
{
	int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.kMostFrequent(arr, n, k) << endl; 
    }

	return 0; 
} 
  // } Driver Code Ends