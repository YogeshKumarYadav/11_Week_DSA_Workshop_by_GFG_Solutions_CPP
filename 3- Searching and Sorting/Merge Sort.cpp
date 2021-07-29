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
    void merge(int arr[], int l, int m, int r)
    {
        // Your code here
        int x=m-l+1;
        int y=r-m;
        int a[x],b[y];
        for(int i=0;i<x;i++)
            a[i]=arr[l+i];
        for(int i=0;i<y;i++)
            b[i]=arr[m+1+i];
            
        int i=0,j=0,k=l;
        while(i<x && j<y)
        {
            if(a[i]<b[j])
            {   arr[k]=a[i];
                i++;
                k++;
            }
            else
            {   arr[k]=b[j];
                j++;
                k++;
            }
        }
        
        while(i<x)
        {   arr[k]=a[i];
            i++;
            k++;
        }
        while(j<y)
        {   arr[k]=b[j];
            j++;
            k++;
        }    
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r)
        {   int m=l+(r-l)/2;
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,r);
            merge(arr,l,m,r);
        }
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends