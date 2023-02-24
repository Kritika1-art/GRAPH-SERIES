//GFQ QUESTION

// PROBLEM STATEMENT:

// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.


/*Example 1:

Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 

Output: 1

Explanation: 

1->2->3->4->1 is a cycle.
*/


// CODE:


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
  
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
	
	int vis[V]={0};
	queue<pair<int,int>>q;
	q.push({1,-1});
	vis[1] = 0;
	while(!q.empty())
	{
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();

		for(auto it:adj[node])
		{
			if(!vis[it])
			{
				vis[it] = 1;
				q.push({it,node});
			}
			else if(it!=parent)
			{
				return true;
			}
		}
	}

	return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
