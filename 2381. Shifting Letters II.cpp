// You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.
// Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').
// Return the final string after all such shifts to s are applied.

//Approach 1: Brute Force
//T.C : o(n*m) n = s.size() && m = shifts.size()
//S.C : O(1)

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        for(auto shift : shifts){
            int start = shift[0];
            int end = shift[1];
            int dir = shift[2];

            for(int i = start; i <= end; i++){
                if(dir == 1){
                    if(s[i] == 'z')s[i] = 'a';
                    else s[i] = s[i]+1;
                }
                if(dir == 0){
                    if(s[i] == 'a')s[i] = 'z';
                    else s[i] = s[i] -1;
                }
            }
        }
        return s;
    }
};


//Approach 2: Difference Array Approach
//T.C : O(shifts.size())
//S.C : O(26)

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diffArray(s.size(),0);

        //Build difference Array
        for(auto shift : shifts){
            int start = shift[0];
            int end = shift[1];
            int dir = shift[2];

            diffArray[start]+= (dir == 1) ? 1 : -1;
            if(end+1 < s.size())(diffArray[end+1]-= (dir == 1)? 1 : -1 ) ; 
        }
        //Find cummulative sum
        for(int i = 1; i < s.size(); i++){
            diffArray[i] +=diffArray[i-1];
        }
        for(int i = 0; i < s.size(); i++){
            int shift = diffArray[i] % 26;

            if(shift < 0 )shift+=26;

            s[i] = ((s[i] - 'a') + shift)%26 + 'a'; 
        }
        return s;
    }
};
