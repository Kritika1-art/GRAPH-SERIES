// How Do we store input in a  Graph?


// there are two ways to store a graph:
1. Adjacency Matrix
2. Adjacency list


Adjacency Matrix:

here we define a 2-D matrix: adj[nodes+1][nodes+1]

and where the edges say that are connected we just have to write adj[u][v] = 1 (and adj[v][u] = 1 in case of undirected graph)


Let's see the code:

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int nodes,edges;
	cin>>nodes>>edges;

	int adj[n+1][n+1];

	for(int i=0;i<edges;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u][v] = 1;
		adj[v][u] = 1;  // in case of undirected graph
	}
	return 0;
}

Now it given the space complexity of O(n^2), that's  why  we use other way to store the graph


Adjacency list:

here we use vector of array to store the graph 

let's say we have 5 nodes, so to store 5 nodes:

1->
2->
3->
4->
5->

Here every node has space to know about how many nodes a single node is connected.


Syntax: vector<int>adj[n+1]


Code:

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int nodes,edges;
	cin>>nodes>>edges;

	vector<int>adj[n+1];

	for(int i=0;i<edges;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);   // in case of undirected graph
	}
	return 0;
}