Question : You are given two strings of the same length s1 and s2 and a string baseStr.

We say s1[i] and s2[i] are equivalent characters.

For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
Equivalent characters follow the usual rules of any equivalence relation:

Reflexivity: 'a' == 'a'.
Symmetry: 'a' == 'b' implies 'b' == 'a'.
Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.

Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.


  //Approach : BFS
  //T.C : O(n)
  //S.C : O(n)

  class Solution {
public:
    char dfs(unordered_map<char,vector<char>> &mpp, char ch, vector<bool>&vis){
        vis[ch-'a'] = true;

        char minCh = ch;
        for(char &c : mpp[ch]){
            if(!vis[c - 'a']){
                minCh = min(minCh,dfs(mpp,c,vis));
            }
        }
        return minCh;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();

        unordered_map<char,vector<char>> mpp;
        string ans = "";
        for(int i = 0; i < n; i++){
            mpp[s1[i]].push_back(s2[i]);
            mpp[s2[i]].push_back(s1[i]);
        }

        for(int i = 0; i < baseStr.size(); i++){
            char ch = baseStr[i];
            
            vector<bool> vis(26,0);
            
            char minCh = dfs(mpp,ch,vis);

            ans += minCh;
        }
        return ans;
    }
};
