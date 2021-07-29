#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
static bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> ans(n, -1);
        sort(arr, arr+n, cmp);
        int pro = 0, count = 0, j;
        
        for(int i=0; i<n; i++)
        {   j = (arr[i].dead - 1) > n-1? n-1: arr[i].dead - 1;
            while(j >= 0)
            {   if(ans[j] == -1)
                {   ans[j] = arr[i].profit;
                    break;
                }
                j--;
            }
        }
        for(int i=0; i<n; i++)
            if(ans[i] != -1)
            {   count++;
                pro += ans[i];
            }
        
        return {count, pro};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends