
//Question : Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

//Approach : Using min heap 
//T.C : O(m*n*log(m*n))
//S.C : O(m*n)

class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<pair<int,int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<P, vector<P> , greater<P>> pq;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int row = 0; row < m; row++){
            for(int col : {0,n-1}){
                pq.push({heightMap[row][col],{row,col}});
                vis[row][col] = true;
            }
        }
        for(int col = 0; col < n; col++){
            for(int row : {0,m-1}){
                pq.push({heightMap[row][col],{row,col}});
                vis[row][col] = true;
            }
        }

        int ans = 0;
        while(!pq.empty()){
            P curr= pq.top();
            int height = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            pq.pop();

            for(auto &dir : direction){
                int x_ = x + dir.first;
                int y_ = y + dir.second;

                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && !vis[x_][y_]){
                    ans += max( height - heightMap[x_][y_] , 0); 

                    pq.push({max(height,heightMap[x_][y_]),{x_,y_}});
                    vis[x_][y_] = true;
                }
            }
        }
        return ans;
    }
};
