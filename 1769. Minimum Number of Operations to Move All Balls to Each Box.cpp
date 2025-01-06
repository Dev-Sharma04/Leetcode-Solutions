//Question : You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.
// In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.
// Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.
// Each answer[i] is calculated considering the initial state of the boxes.

//Approach 1 : BruteForce
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(),0);
        //min moves to move all 1 to ith idx
        for(int i = 0; i < boxes.size(); i++){
            for(int j = 0; j < boxes.size(); j++){
                if(boxes[j] == '1')ans[i]+=abs(j-i);
            }
        }
        return ans;
    }
};

//Approach 2: Using sum of left and right moves
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n,0);

        int ballsLeft  = 0, movesLeft = 0, ballsRight = 0, movesRight = 0;

        for(int i = 0; i < n ; i++){
            //Left Traversal
            ans[i] +=movesLeft;
            ballsLeft +=boxes[i] - '0';
            movesLeft += ballsLeft;

            //Right Traversal
            int j = n - i - 1;
            ans[j] +=movesRight;
            ballsRight += boxes[j] - '0';
            movesRight +=ballsRight;
        }
        return ans;
    }
};
