//Question : You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.
//Return the number of servers that communicate with any other server.

 



//Approach : Brute Force
//T.C : O(m*n*(n+m))
//S.C : O(1)

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int system = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(grid[i][j] == 1){
                    bool isAvail = 0;
                    for(int col = 0; col < n; col++){
                        if(grid[i][col] == 1 && col != j){
                            isAvail = 1;
                        }
                    }
                    if(isAvail)system++;
                    else{
                        for(int row = 0;row < m; row++){
                            if(grid[row][j] == 1 && row != i){
                                isAvail = true;
                            }
                        }
                        if(isAvail)system++;
                    }
                }
            }
        }
        
        return system;
    }
};

//Approach 2: Using hashmap
//T.C : O(m*n)
//S.C : O(m+n)

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int system = 0;
        vector<int> idxRowCnt(m,0);
        vector<int> idxColCnt(n,0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    idxRowCnt[i] +=1;
                    idxColCnt[j] +=1;
                }
            }
        }
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && (idxRowCnt[i] > 1 || idxColCnt[j] > 1))system++;
            }
        }
        
        return system;
    }
};
