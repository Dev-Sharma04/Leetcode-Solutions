//Question :You are given two string arrays words1 and words2.
// A string b is a subset of string a if every letter in b occurs in a including multiplicity.
// For example, "wrr" is a subset of "warrior" but is not a subset of "world".
// A string a from words1 is universal if for every string b in words2, b is a subset of a.
// Return an array of all the universal strings in words1. You may return the answer in any order.

//Approach 1: Using hashmap
//T.C : O(n*l1 + m*l2)
//S.C : O(1)
class Solution {
public:
    bool check(vector<int> &freq2, vector<int>&temp){
        for(int i = 0; i < 26; i++){
            if(temp[i] < freq2[i])return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> freq2(26,0);
        for(string &word : words2){
            int temp[26] = {0};
            for(char ch : word){
                temp[ch-'a']++;
                freq2[ch-'a'] = max(freq2[ch-'a'],temp[ch-'a']);
            }
        }

        for(string &word : words1){
            vector<int> temp(26,0);
            for(char &ch : word)temp[ch-'a']++;

            if(check(freq2,temp))ans.push_back(word);
        }
        return ans;
    }
};
