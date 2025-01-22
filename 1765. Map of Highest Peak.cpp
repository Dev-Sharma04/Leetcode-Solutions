//Question : You are given an integer matrix isWater of size m x n that represents a map of land and water cells.
// If isWater[i][j] == 0, cell (i, j) is a land cell.
// If isWater[i][j] == 1, cell (i, j) is a water cell.
// You must assign each cell a height in a way that follows these rules:
// The height of each cell must be non-negative.
// If the cell is a water cell, its height must be 0.
// Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
// Find an assignment of heights such that the maximum height in the matrix is maximized.

//Approach : MultiSource BFS
//T.C : O(m*n)
//S.C : O(m*n)

class Solution {
public:
    vector<pair<int,int>> direction = {{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> height(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(isWater[i][j] == 1){
                    q.push({i,j});
                    height[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;

                for(auto &dir : direction){
                    int X = x+ dir.first;
                    int Y = y + dir.second;

                    if(X >= 0 && X < m && Y >= 0 && Y < n && height[X][Y] == -1 ){
                        height[X][Y] = height[x][y] +1;
                        q.push({X,Y});
                    }
                }
            }
        }
        return height;
    }
};
