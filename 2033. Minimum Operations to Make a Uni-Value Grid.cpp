Question : You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

  //Approach : Simulation
  //T.C : O(n*m*log(m*n))
  //S.C : O(n*m)

  class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();


        vector<int> v;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n; j++){
                v.push_back(grid[i][j]);
            }
        }        
        sort(v.begin(),v.end());
        int median = v[(m*n)/2];

        
        int cnt = 0;
        for(int i = 0; i < v.size(); i++){
            if(abs(v[i] - median) % x != 0)return -1;
            else cnt+= abs(v[i]-median)/x;
        }
        return cnt;
    }
};
