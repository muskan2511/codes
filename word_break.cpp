//O()
// not complete
#include<bits/stdc++.h>
using namespace std;

vector<string>v{"mobile","samsung","sam","sung","man","mango", 
                "icecream","and","go","i","like","ice","cream"};
string s="samsungandmangok";
int m=v.size(),n=s.size();

int search(string word) 
    {for (int i = 0; i < m; i++) 
        if (v[i].compare(word) == 0) 
           return 1; 
    return 0; 
} 

int main()
{
    int i,j,k,p,a[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        if(search(s.substr(i,1)))
            a[i][i]=1;
    }
    for(i=1;i<n;i++)
    {
        p=i;
        for(j=0;j<n-i;j++)
        {
            if(search(s.substr(j,p-j+1)))
            {
                a[j][p]=1;
                p++;
                continue;
            }
            for(k=j;k<p;k++)
            {
                if(a[j][k] && a[k+1][p])
                {
                    a[j][p]=1;
                    break;
                }
            }
            p++;
        }
    }
    cout<<n<<endl;
    cout<<"-------------"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"-------------";
    cout<<endl;
    if(a[0][n-1]==1)
        cout<<"true";
    else
        cout<<"false";
    return 0;
}
