#include <bits/stdc++.h>
using namespace std;

int main() 
{
	long long int n=3,i,j,k;
	// cin>>n;
	long long int a[n]={1,2,3};
	k=pow(2,n);
	for(i=0;i<k;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i & (1<<j))	//bitwise and operation
				cout<<a[j];
		}
		cout<<endl;
	}
	
    return 0;
}
