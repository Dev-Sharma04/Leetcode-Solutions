Question : You are given an m x n integer matrix grid and an array queries of size k.

Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:

If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
Otherwise, you do not get any points, and you end this process.
After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.

Return the resulting array answer.

  //Approach : BFS
//T.C : O(Q*m*n) : TLE
//S.C : O(m*n)

  class Solution {
public:
    int m,n;
    vector<pair<int,int>> direction = {{-1,0},{1,0},{0,1},{0,-1}};
    int solve(int start, vector<vector<int>>& grid){
        set<pair<int,int>> s;
        queue<pair<int,int>> q;
        if(start <= grid[0][0])return 0;
        q.push({0,0});
        int cnt = 0;


        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if(start > grid[x][y]){
                if(!s.count({x,y})){
                    cnt++;
                }
            }
            s.insert({x,y});

            for(auto &dir : direction){
                int x_ = x + dir.first;
                int y_ = y + dir.second;

                if(x_ >= 0 && x_ < m && y_>= 0 && y_ < n){
                    if(!s.count({x_,y_}) && start > grid[x_][y_])q.push({x_,y_});
                }
            }
        }

        return cnt;
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        m = grid.size();
        n = grid[0].size();
        vector<int> ans;
        for(auto& query : queries){
            ans.push_back(solve(query,grid));
        }
        return ans;
    }
};


//Approach : Using minheap
//T.C : O(Q + m*n*log(m*n))
//S.C : O(Q)

class Solution {
public:
    int m,n;
    vector<pair<int,int>> direction = {{-1,0},{1,0},{0,1},{0,-1}};
    
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        m = grid.size();
        n = grid[0].size();
        int Q = queries.size();
        vector<int> ans(Q,0);

        vector<pair<int,int>> sortedQ;
        for(int i = 0; i < Q; i++){
            sortedQ.push_back({queries[i],i});
        }
        sort(sortedQ.begin(),sortedQ.end());

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        int cnt = 0;
        pq.push({grid[0][0],0,0}); // grid[x][y], x, y

        vis[0][0] = true;

        for(int i = 0; i < Q; i++){
            int query = sortedQ[i].first;
            int idx = sortedQ[i].second;
            while(!pq.empty() && pq.top()[0] < query){
                int x = pq.top()[1];
                int y = pq.top()[2];

                pq.pop();
                cnt++;
                
                for(auto &dir : direction){
                    int x_ = x + dir.first;
                    int y_ = y + dir.second;

                    if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && !vis[x_][y_]){
                        pq.push({grid[x_][y_],x_,y_});
                        vis[x_][y_] = true;
                    } 
                }
            }
            ans[idx] = cnt;
        }
        return ans;
    }
};
