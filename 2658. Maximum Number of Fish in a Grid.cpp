//Question : You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:
// A land cell if grid[r][c] = 0, or
// A water cell containing grid[r][c] fish, if grid[r][c] > 0.
// A fisher can start at any water cell (r, c) and can do the following operations any number of times:
// Catch all the fish at cell (r, c), or
// Move to any adjacent water cell.
// Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.
// An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.



//Approach : Using BFS and DFS both
//T.C : O(m*n)
//S.C : BFS - O(m*n) DFS - O(1)

class Solution {
public:
    vector<pair<int,int>> direction = {{0,1},{0,-1},{1,0}, {-1,0}};
    int n,m;
    int bfs(int x, int y, vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        q.push({x,y});
        int val = grid[x][y];
        grid[x][y] = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int i = node.first;
            int j = node.second;

            for(auto &dir : direction){
                int i_  = i+dir.first;
                int j_ = j+dir.second;

                if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n &&  grid[i_][j_] > 0){
                    q.push({i_,j_});
                    val += grid[i_][j_];
                    grid[i_][j_] = 0;
                }
            }
        }
        return val;
    }

    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || i >= m ||j < 0 || j >= n || grid[i][j] == 0)return 0;
        int val = grid[i][j];
        grid[i][j] = 0;
        
        for(pair<int,int> &dir : direction){
            int x = i + dir.first;
            int y = j +dir.second;
            val += dfs(x,y,grid);
        }
        return val;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
         m = grid.size();
         n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j= 0; j < grid[0].size(); j++){
                if(grid[i][j] != 0)ans = max(ans,bfs(i,j,grid));
            }
        }
        
        return ans;
    }
};
