//Question :You are given a 0-indexed string array words.Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:

// isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix and a suffix of str2, and false otherwise.
// For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.
// Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.

//Approach1 : Simple Traversal
//T.C : O(n^2*m)
//S.C : O(1)
class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2){
        int i = 0;
        while(i < s1.size()){
            if(s1[i] != s2[i])return false;
            else i++;
        }
        
        int j = s2.size()-s1.size();
        i =0 ;
        while(j < s2.size()){
            if(s1[i] != s2[j])return false;
            else {
                i++;
                j++;
            }
        }

        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = i+1; j < words.size(); j++){
                if(isPrefixAndSuffix(words[i],words[j]))cnt++;
            }
        }
        return cnt;
    }
};
