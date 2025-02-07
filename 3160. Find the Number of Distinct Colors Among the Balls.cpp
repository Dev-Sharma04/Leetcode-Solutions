//Question : You are given an integer limit and a 2D array queries of size n x 2.
// There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.
// Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.
// Note that when answering a query, lack of a color will not be considered as a color.



//Approach : Using hash map
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int,int> color; //color -> cnt
        unordered_map<int,int> ballMpp; //ball -> color
        for(auto & query : queries){
            int ball = query[0];
            int col = query[1];
            
            if(ballMpp.count(ball)){
                int prevCol = ballMpp[ball];
                color[prevCol]--;
                if(color[prevCol] == 0)color.erase(prevCol);

            }
            ballMpp[ball] = col;
            color[col]++;
            ans.push_back(color.size());
        }
        return ans;
    }
};
