//Question : You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at position (r, c) on the matrix. Two robots are playing a game on this matrix.
// Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).
// At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points from the cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect with one another.
// The first robot wants to minimize the number of points collected by the second robot. In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally, return the number of points collected by the second robot

//Approach 1 : Using Prefix Sum and following game strategy
//T.C : O(n)
//S.C : O(1)

// what have we done? So, we realised that robot 1 has only two moves, i.e down or right.
// So, at every time if he goes down then all the above remaining row ele will go to robot 2
// Or if he moves right then, he gets two choice either remaing row0 ele or down row 1 ele

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
      //we accumulate all the val of row 0
        long long firstRowRemainSum = accumulate(grid[0].begin(),grid[0].end(),0LL);
      //it will store all the remaining sum of row 2 if it is not occupied by robot1
        long long secondRowRemainSum = 0;
      //it will store the ans
        long long minimizedRobot2Sum = LONG_LONG_MAX;

        for(int robot1Col = 0; robot1Col < grid[0].size(); robot1Col++){
          //since it has occupied the ele so robot2 ke lie ye val available nhi rhegi
            firstRowRemainSum -= grid[0][robot1Col];
            //checking ki robot 2 ke lie available choice mai kya best h
          
            long long bestOfRobot2 =  max(firstRowRemainSum,secondRowRemainSum);
            minimizedRobot2Sum = min(minimizedRobot2Sum,bestOfRobot2);
            secondRowRemainSum += grid[1][robot1Col];
        }
        return minimizedRobot2Sum; 
    }
};
