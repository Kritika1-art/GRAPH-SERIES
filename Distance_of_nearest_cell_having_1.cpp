// GFG Question:

// PROBLEM STATEMENT:

/* Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.

Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}

Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}

Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.
*/



// we will use BFS as here we have to travel step wise
// so we'll take a queue and put all the 1's in a queue

queue<pair<int,int>,int>q;
		  row, col  counter

// and then try to traverse it in all 4 directions


// CODE:

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int r = grid.size();
	    int c = grid[0].size();
	    
	    vector<vector<int>>vis(r,vector<int>(c,0));
	    vector<vector<int>>ans(r,vector<int>(c,0));
	    
	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({{i,j},0});
	                vis[i][j] = 1;
	            }
	        }
	    }
	    int delrow[] = {-1,0,+1,0};
	    int delcol[] = {0,+1,0,-1};
	    while(!q.empty())
	    {
	        int a = q.front().first.first;
	        int b = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        
	        ans[a][b] = steps;
	        
	        for(int i=0;i<4;i++)
	        {
	            int nrow = a+delrow[i];
	            int ncol = b+delcol[i];
	            
	            if(nrow>=0 && nrow<r && ncol>=0 && ncol<c && vis[nrow][ncol]==0)
	            {
	                vis[nrow][ncol]=1;
	                q.push({{nrow,ncol},steps+1});
	            }
	        }
	        
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends


