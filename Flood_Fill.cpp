// GFG QUESTION

// Problem Statement:
// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.
// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.
// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor


/*Example 1:

Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.

Output: {{2,2,2},{2,2,0},{2,0,1}}

Explanation: From the center of the image 
(with position (sr, sc) = (1, 1)), all 
pixels connected by a path of the same color
as the starting pixel are colored with the new 
color.Note the bottom corner is not colored 2, 
because it is not 4-directionally connected to 
the starting pixel.
*/

// PRO TIP:

// Whenever you have to traverse in 4 directions,use this :

// delrow[] = {-1,0,+1,0}

// delcol[] = {0,+1,0,-1}

//I've solved using DFS 

// CODE:

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>& image, vector<vector<int>>&vis,int oldcolor,int newColor)   
    {
        vis[row][col] = newColor;
        int r = image.size();
        int c = image[0].size();
        int delrow[] = {-1,0,+1,0};
	    int delcol[] = {0,+1,0,-1};   

		for(int a=0;a<4;a++)
		{
		    int nrow = row+delrow[a];
		    int ncol = col+delcol[a];
		    if(nrow>=0 && nrow<r && ncol>=0 && ncol<c && image[nrow][ncol]==oldcolor && vis[nrow][ncol]!=newColor)
		    {
		        dfs(nrow,ncol,image,vis,oldcolor,newColor);
		    }
		}
	}
        
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
	    int oldcolor = image[sr][sc];
        vector<vector<int>>vis=image;
	    dfs(sr,sc,image,vis,oldcolor,newColor);
        return vis;
    }
};

