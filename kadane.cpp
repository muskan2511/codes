#include<bits/stdc++.h>
using namespace std;

vector<int> kadane(int a[], int n)  
{  
    int cur = 0, ans = 0,prev=0,l=0,r=-1;  
    int i;  
    for (i = 0; i < n; i++)  
    {  
        cur += a[i];  
        if (cur < 0) 
        {
            cur = 0;
            prev=i+1;
        } 
            
        if(cur>ans)
        {
            ans=cur;
            l=prev;
            r=i;
        } 
    }  
    return vector<int>{l,r,ans};  
}  

int main()
{
    int a[]={-11, -10, 20, -5, 3, 5, -8, 13, -10};
    int n=sizeof(a)/sizeof(a[0]);
    vector<int>ans=kadane(a,n);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    cout<<"sum : "<<ans[2]<<endl;
}
