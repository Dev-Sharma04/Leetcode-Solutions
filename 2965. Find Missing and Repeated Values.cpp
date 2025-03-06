Question : You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.


//Approach : Using vector
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans;
        int rep = -1;
        vector<bool> vis(n*n+1,false);
        for(int i  = 0 ; i < n ; i++){
            for(int j = 0; j <  n; j++){
                if(vis[grid[i][j]] == true)rep = grid[i][j];
                else vis[grid[i][j]] = true;
            }
        }
        int mis = -1;
        for(int i = 0; i < vis.size(); i++){
            if(vis[i] == false){
                mis = i;
            }
        }
        return {rep,mis};
    }
};
