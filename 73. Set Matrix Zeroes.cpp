Question  : Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.


//Approach : Simulation
//T.C : O(m*n)
//S.C : O(m*n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>> q;
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0)q.push({i,j});
            }
        }

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            //row zero
            for(int i = 0; i < m; i++){
                matrix[i][y] = 0;
            }
            //col zero
            for(int j = 0; j < n; j++){
                matrix[x][j] = 0;
            }
        }
        return ;
    }
};
