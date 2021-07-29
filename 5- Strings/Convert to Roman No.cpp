#include <bits/stdc++.h>
using namespace std;


string convertToRoman(int ) ;


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		
	cout << convertToRoman(N);
	cout<<endl;
		
	}
	return 0;
}// } Driver Code Ends


/*you are required to complete 
this function*/

// n :given number that you are require to convert
string convertToRoman(int n) 
{   int no[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string rom[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string str="";
    int i=0;
    while(n>0)
    {   int d=n/no[i];
        n=n%no[i];
        while(d)
        {   str.append(rom[i]);
            d--;
        }
        i++;
    }
    return str;
}