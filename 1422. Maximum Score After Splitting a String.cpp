/* Given a string s of 0 and 1. Give the maximum score you can get by segregating the string into two subparts, left and right. 
The score is defined as no. of zeroes in the left part and no. of ones in right part.*/

//Approach 1: Brute Force
// T.C : O(n^2)
// S.C : O(1)

class Solution {
public:
  
    int maxScore(string s) {
        int ans = 0;
        for(int i = 0; i < s.size() - 1; i++){
            int score = 0;
            for(int j = 0; j <= i; j++){
                if(s[j] == '0')score++;
            }
            for(int j = i+1; j < s.size(); j++){
                if(s[j] == '1')score++;
            }
            ans = max(score,ans);
        }
        return ans;
    }
};


