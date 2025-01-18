//Question :Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:
// 1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
// 2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
// 3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
// 4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
// Notice that there could be some signs on the cells of the grid that point outside the grid.
// You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.
// You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.
// Return the minimum cost to make the grid have at least one valid path.


//Approach 1 : BackTracking TLE
//T.C : O(4^(m*n))
//S.C : O(m*n)
class Solution {
public:
    int m , n;
    vector<pair<int,int>> dir  = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int dfs(int x, int y,vector<vector<int>>& grid,vector<vector<bool>> &vis, int cost ){
        if(x == m-1 && y == n-1)return cost;
        vis[x][y] = true;

        //explore all possibilites
        int minCost = INT_MAX;
        for(int i = 0; i < 4; i++){
            int x_ = x + dir[i].first;
            int y_ = y + dir[i].second;

            if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && !vis[x_][y_] ){
                int newCost = cost + ((grid[x][y] - 1 != i)? 1 : 0);
                minCost = min( minCost, dfs(x_,y_, grid,vis,newCost));
            }
        }

        vis[x][y] = false;
        return minCost;
    }
    int minCost(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();


//Approach 2 : Using Dijkstra
//T.C : O(m*n)
//S.C : O(m*n)

class Solution {
public:
    typedef  pair<int,pair<int,int>> P;
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        priority_queue<P, vector<P> , greater<P>> pq;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            P node = pq.top();
            pq.pop();
            int cost = node.first;
            int x = node.second.first;
            int y = node.second.second;

            if(x == m-1 && y == n-1)return cost;
            if(vis[x][y] == true)continue;
            vis[x][y] = true;

            for(int i = 0; i < 4; i++){
                int x_ = x + dir[i].first;
                int y_ = y + dir[i].second;

                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && !vis[x_][y_]){
                    int newCost = cost + (grid[x][y] -1 != i ? 1 : 0);
                    pq.push({newCost,{x_,y_}});
                }
            }

        }
        return -1;
    }
};

        vector<vector<bool>> vis(m,vector<bool>(n,0));    

        return dfs(0,0,grid,vis,0);    //backtracking wala code se exploring all paths
    }
};
