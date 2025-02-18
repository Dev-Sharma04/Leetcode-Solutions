//Question : You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.
// A 0-indexed string num of length n + 1 is created using the following conditions:
// num consists of the digits '1' to '9', where each digit is used at most once.
// If pattern[i] == 'I', then num[i] < num[i + 1].
// If pattern[i] == 'D', then num[i] > num[i + 1].
//Return the lexicographically smallest possible string num that meets the conditions.

//Approach : Using STL - next_permutation
//T.C : O(n*(n+1)!)
//S.C : O(1)


class Solution {
public:
    bool matchPattern(string &num, string &pattern){

        for(int i = 0; i < pattern.size(); i++){
            if((pattern[i] == 'I' && num[i] > num[i+1])
            ||(pattern[i] == 'D' && num[i] < num[i+1]) )return false;
        }
        return true;
    }
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string ans = "";

        for(int i = 1; i<=n+1; i++){
            ans += i + '0';
        }
        while(!matchPattern(ans,pattern)){
            next_permutation(ans.begin(),ans.end());
        }
        return ans;
    }
};
