//Question : You are given an m x n grid where each cell can have one of three values:
// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


//Approach : Using multisource BFS
//T.C : O(m*n)
//S.C : O(m*n)

class Solution {
public:
    vector<pair<int,int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int freshOrange = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2)q.push({i,j});

                else if(grid[i][j] == 1)freshOrange++;
            }
        }
        if(freshOrange== 0)return 0;
        
        int cnt = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                pair<int,int> curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                
                for(auto &dir : direction){
                    int x_ = x + dir.first;
                    int y_ = y + dir.second;

                    if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && grid[x_][y_] == 1){
                        grid[x_][y_] = 2;
                        q.push({x_,y_});
                        freshOrange--;
                    }
                }
            }
            cnt++;
        }
        return (freshOrange == 0) ? cnt-1:-1;
    }
};
