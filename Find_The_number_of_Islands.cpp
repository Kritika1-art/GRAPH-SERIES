
//Problem Statement:
// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.
// Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.


/*Input:
grid = {{0,1},{1,0},{1,1},{1,0}}

Output:
1

Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.*/


// we have to create a 2-D vis array as we have to traverse a matrix 


// PRO TIP:

// whenever you want to traverse in 8 directions, you this for loops they cover all 8 directions

for(int i=-1;i<=1;i++)
{
	for(int i=-1;i<=1;i++)
	{
		//any traversal stuff
	}
}

// Code:


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void dfs(int r,int c,int row,int col,vector<vector<char>>grid,vector<vector<int>>&vis)
    {
        vis[r][c] = 1;
        
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int nrow = i+r;
                int ncol = j+c;
                if(nrow>=0 && nrow<row && ncol>=0 && ncol<col && !vis[nrow][ncol] && grid[nrow][ncol]=='1')
                {
                    dfs(nrow,ncol,row,col,grid,vis);
                }
            }
        }
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    cnt=cnt+1;
                    dfs(i,j,n,m,grid,vis);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends