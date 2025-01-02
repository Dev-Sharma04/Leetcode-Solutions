/* You are given a 0-indexed array of strings words and a 2D array of integers queries.
 Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
 Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.*/

// Approach 1: BruteForce
// T.C = O(n^2) //TLE
// S.C = O(n);

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(),0);
        for(int i = 0; i < queries.size(); i++){
            int start = queries[i][0];
            int end = queries[i][1];

            for(int idx = start ; idx <= end; idx++ ){
                
                if((words[idx][0] == 'a' || words[idx][0] == 'e'|| words[idx][0] == 'i'|| words[idx][0] == 'o'|| words[idx][0] == 'u')
                && (words[idx][words[idx].size()-1] == 'a' || words[idx][words[idx].size()-1] == 'e' || words[idx][words[idx].size()-1] == 'i' ||
                words[idx][words[idx].size()-1] == 'o' || words[idx][words[idx].size()-1] == 'u') ){
                    ans[i]++;
                }
                
            }
        }
        return ans;
    }
};


// Approach 2: Optimised using PrefixSum
//T.C : O(words.size()+query.size())
//S.C : O(words.size())

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> cnt(words.size(),0);
        vector<int> ans(queries.size(),0);
        set<char> s;
        s.insert('a');
        s.insert('e');
        s.insert('i');
        s.insert('o');
        s.insert('u');
        int sum = 0;
        for(int i = 0; i < words.size(); i++){
            if(s.find(words[i][0]) != s.end() && s.find(words[i][words[i].size()-1]) != s.end() ){
                sum++;
            }
            cnt[i] = sum;
        }
        
        for(int i = 0; i < queries.size(); i++){
            int start = queries[i][0];
            int end = queries[i][1];

            ans[i] = cnt[end] - ((start ==  0) ? 0 : cnt[start - 1]) ;
            
        }
        return ans;
    }
};
