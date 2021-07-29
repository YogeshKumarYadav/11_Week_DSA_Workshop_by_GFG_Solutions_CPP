//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> arr, int k) {
    //code here
    int n=arr.size();
    int l=0,r=n-1,m;
    while(l<=r)
    {   m=l+(r-l)/2;
        if(arr[m]==k)
            return m;
            
        else if(arr[m]>=arr[l])
        {
            if(arr[m]>=k && arr[l]<=k)
                r=m-1;
            else
                l=m+1;
        }
        else
        {
            if(arr[m]<=k && arr[r]>=k)
                l=m+1;
            else
                r=m-1;
        }
    }
    return -1;
    
}