Question : You are given a string word, and an integer numFriends.

Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:

word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
All the split words are put into a box.
Find the lexicographically largest string from the box after all the rounds are finished.




//Approach : Simulation
//T.C : O(n^2)
//S.C : O(1)

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        string ans ;

        if(numFriends == 1)return word;
        int longestPossibleLen = n - (numFriends - 1);
        for(int i = 0; i < n; i++){
            int canTakeLen = min(longestPossibleLen, n -i);
            ans = max(ans, word.substr(i,canTakeLen));

        }
        

        return ans;
    }
};
