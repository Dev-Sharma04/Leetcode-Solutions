Question : You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

//Approach : Using hash Map
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string,int> mpp;

        for(string &word : words){
            string rev = word;
            swap(rev[0],rev[1]);

            if(mpp[rev] > 0){
                ans += 4;
                mpp[rev]--;
            }
            else{
                mpp[word]++;
            }
        }

        for(auto &it : mpp){
            if(it.first[0] == it.first[1] && it.second > 0){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};
