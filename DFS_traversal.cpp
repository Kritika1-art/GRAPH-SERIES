// It is a traversal technique to access the nodes

// there are are two types:
// 1.BFS Breadth First Search      (Level wise traversal)

// 2. DFS  Depth First Search     (Depth wise traversal)

// Here I'm Traversing using DFS:


// for DFS traversal we use Recursion


#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>&vis,vector<int>adj[])
{
	vis[node] = 1;

	cout<<node<<" ";

	for(auto it:adj[node])
	{
		if(!vis[it])
		{
			dfs(it,vis,adj);
		}
	}
}
int main()
{
	int nodes,edges;
	cin>>nodes>>edges;
	vector<int>adj[nodes+1];
	for(int i=0;i<edges;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);   // in case of undirected graph
	}
	vector<int>vis(nodes+1,0);

	for(int i=0;i<nodes;i++)
	{
		if(!vis[i])
		{
			dfs(i,vis,adj);
		}
	}

	return 0;
}