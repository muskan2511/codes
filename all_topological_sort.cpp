#include<bits/stdc++.h>
using namespace std;

int n,e;
vector<int>ans;
vector<vector<int>>v(1000);
int vis[1000]={0};
int in[1000]={0};

void dfs()
{
    int i,j,flag=0;
    for(i=0;i<n;i++)
    {
        if(vis[i]==0 && in[i]==0)
        {
            vis[i]=1;
            ans.push_back(i);
            for(j=0;j<v[i].size();j++)
                in[v[i][j]]--;
            dfs();
            vis[i]=0;
            ans.pop_back();
            for(j=0;j<v[i].size();j++)
                in[v[i][j]]++;
            flag=1;
        }
    }
    if(flag==0)
    {
        for(j=0;j<ans.size();j++)
            cout<<ans[j]<<" ";
        cout<<endl;
    }
}
int main()
 {
    int i,j,a,b;
    cin>>n>>e;
   
    for(i=0;i<e;i++)
    {
    	cin>>a>>b;
    	v[a].push_back(b);
        in[b]++;
    }
    dfs();
}
