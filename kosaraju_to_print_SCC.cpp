//O(V+E)

// Sample test case
// 5 5         
// 1 0
// 0 2
// 2 1
// 0 3
// 3 4

#include <bits/stdc++.h>
using namespace std;
int n,e;
vector<vector<int>>v(100);	// original graph
vector<vector<int>>vv(100);	//transpose graph
stack<int>s;
int vis[100]={0};

void dfs_original(int i)
{
	int j;
	vis[i]=1;
	for(j=0;j<v[i].size();j++)
		if(vis[v[i][j]]==0)
			dfs_original(v[i][j]);

	s.push(i);
}

void dfs_transpose(int i)
{
	int j;
	vis[i]=1;
	cout<<i<<" ";
	for(j=0;j<vv[i].size();j++)
		if(vis[vv[i][j]]==0)
			dfs_transpose(vv[i][j]);
}

int main()
{
	int i,x,y;
	cin>>n>>e;
	for(i=0;i<e;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		vv[y].push_back(x);
	}
	for(i=0;i<n;i++)
	{
		if(vis[i]==0)
			dfs_original(i);
	}
	for(i=0;i<n;i++)
		vis[i]=0;

	stack<int>temp=s;
	cout<<"elements of stack from top to bottom : "<<endl;
	while(!temp.empty())
	{
		cout<<temp.top()<<" ";
		temp.pop();
	}
	cout<<endl;

	cout<<"SCC are : "<<endl;
	while(!s.empty())
	{
		i=s.top();
		s.pop();
		if(vis[i]==0)
		{
			dfs_transpose(i);
			cout<<endl;
		}
	}
	return 0;
}
