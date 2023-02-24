//GFG QUESTION

// PROBLEM STATEMENT:

// Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

// Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group


/*Input:
[
 [1, 0, 1],				1			2
 [0, 1, 0],				 \
 [1, 0, 1]				  3
]*/

// Output: 2



// If I say in normal words than total no. of disconnected graphs is  actually a totally no. of province.


// I'm solving it using dfs traversal

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int vis[],int a,vector<int>adjlist[])
    {
        vis[a] = 1;
        for(auto it:adjlist[a])
        {
            if(!vis[it])
            {
                dfs(vis,it,adjlist);
            }
        }
    }
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>adjlist[V];
        
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1 && i!=j)	// i!=j means self nodes are ignoring
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
                
            }
        }
        int vis[V] = {0};
        int cnt=0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(vis,i,adjlist);
            }
        }
        // code here
        return cnt;
    }
};


