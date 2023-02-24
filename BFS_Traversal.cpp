// It is a traversal technique to access the nodes

// there are are two types:
// 1.BFS Breadth First Search      (Level wise traversal)

// 2. DFS  Depth First Search     (Depth wise traversal)

// Here I'm Traversing using BFS:


// for BFS traversal we use Queue data structure

#include<bits/stdc++.h>
using namespace std;
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
	int vis[nodes+1] = {0};

	for(int i=0;i<nodes;i++)
	{
		if(!vis[i])
		{
			queue<int>q;
			q.push(i);
			vis[i] = 1;
			while(!q.empty())
			{
				int a = q.front();
				q.pop();
				cout<<a<<" ";
				for(auto it: adj[a])
				{
					if(!vis[it])
					{
						q.push(it);
						vis[it] = 1;
					}
				}

			}
		}
	}
	return 0;
}


// Time: O(N)+O(2E)//total degree

// Space: O(2N) = O(N)
		//visited array and queue
