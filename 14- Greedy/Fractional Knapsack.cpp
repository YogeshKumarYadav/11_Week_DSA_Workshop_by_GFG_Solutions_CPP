
struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(Item a, Item b)
    {   
        return ((double)a.value/(double)a.weight) > ((double)b.value/(double)b.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, cmp);
        double sum = 0, val = 0;
        int i = 0;
        while(sum + arr[i].weight <= W && i < n)
        {
            sum += arr[i].weight;
            val += arr[i].value;
            i++;
        }
        if(W - sum == 0)
            return val;
        if(i != n)
            val += (double)(arr[i].value * (W - sum)) / (double)(arr[i].weight);
        return val;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends