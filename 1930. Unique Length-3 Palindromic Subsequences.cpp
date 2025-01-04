//Question :Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
// A palindrome is a string that reads the same forwards and backwards.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
// For example, "ace" is a subsequence of "abcde".

//Approach 1: Using set 
//T.C : O(26*n)
//S.C : O(26);
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        unordered_set<char> letters;
        for(int i = 0; i < n; i++){
            letters.insert(s[i]);
        }
        int ans = 0;
        for(char ch : letters){
            int leftIdx = -1;
            int rightIdx = -1;

            for(int i = 0; i < n; i++){
                if(s[i] == ch ){
                    if(leftIdx == -1){
                        leftIdx = i;
                    }
                    rightIdx = i;
                }
                
            }
            unordered_set<char> st;
            for(int midIdx = leftIdx+1; midIdx < rightIdx; midIdx++){
                st.insert(s[midIdx]);
            }
            ans += st.size();
        }
        return ans;
    }
};
