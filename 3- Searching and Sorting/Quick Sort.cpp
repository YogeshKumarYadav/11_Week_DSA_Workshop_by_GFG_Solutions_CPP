#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

 // } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int l, int r)
    {
        // code here
        if(l<r)
       {
           int p=partition(arr,l,r);
           quickSort(arr,l,p-1);
           quickSort(arr,p+1,r);
       }
    }
    
    public:
    int partition (int arr[], int l, int r)
    {
        // Your code here
       
       int j=l-1;
       int temp=arr[r],t;
       for(int i=l;i<r;i++)
       {    
           if(arr[i]<=temp && i!=j)
           {    
               j++;    
               swap(arr[i],arr[j]);
           }
       }
       j++;
       swap(arr[r],arr[j]);
       
       return j;
    }
};


// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends