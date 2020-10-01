// https://www.interviewbit.com/problems/flip-array/
#include<bits/stdc++.h>
using namespace std;

int main() 
{
    vector<int>A{9,6 };
    int sum = 0;
    for(auto i : A)
        sum+=i;
    sum = sum/2;
    int n = A.size();
    vector<vector<int>> DP(n+1, vector<int> (sum+1, 9999));

    for(int i=0;i<=n;i++)
    {
        DP[i][0]=0;
    }
    
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=sum; j++)
        {
                
            if(A[i-1] <= j)
            {
                DP[i][j] = min(1 + DP[i-1][j-A[i-1]], DP[i-1][j]);
            }
            
            else
            {
                DP[i][j] = DP[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=sum;i>=0;i--)
    {
        if(DP[n][i]<9999)
        {
            cout<<"answer : "<<DP[n][i];
            break;
        }
    }
    
}
