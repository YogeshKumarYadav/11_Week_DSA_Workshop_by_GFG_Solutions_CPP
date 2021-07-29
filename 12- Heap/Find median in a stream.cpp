#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> qmax;
    priority_queue<int, vector<int>, greater<int>> qmin;
    
    void insertHeap(int &x)
    {   if(qmax.size() == 0)
            qmax.push(x);
        else
        {
            if(x < qmax.top())
                qmax.push(x);
            else
                qmin.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {   if(qmin.size() > qmax.size())
        {   qmax.push(qmin.top());
            qmin.pop();
        }
        if(qmax.size() - qmin.size() == 2)
        {   qmin.push(qmax.top());
            qmax.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if((qmax.size() - qmin.size()) == 1)
    	    return qmax.top();
    	else
    	    return ((qmax.top() + qmin.top())/2);  
    }

};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends