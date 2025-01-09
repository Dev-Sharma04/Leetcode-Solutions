//Question : You are given an array of strings words and a string pref.Return the number of strings in words that contain pref as a prefix.A prefix of a string s is any leading contiguous substring of s.

//Approach 1:using substring
//T.C :O(n)
//S.C :O(1)
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(int i = 0; i < words.size(); i++){
            if(words[i].substr(0,pref.size()) == pref)cnt++;
        }
        return cnt;
    }
};

//Approach 2: Using Trie
