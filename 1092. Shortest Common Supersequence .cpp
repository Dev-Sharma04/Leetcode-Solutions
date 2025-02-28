Question : Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

  //Approach : DP - bottom up
  //T.C : O(m*n)
  //S.C : O(m*n)

  class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 0; i < m+1; i++){
            for(int j = 0; j < n+1; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = i+j;
                }
                else if(str1[i-1] == str2[j-1]){
                    dp[i][j]  =  1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string ans = "";
        int i = m, j = n;
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                ans.push_back(str1[i-1]);
                j--;
                i--;
            }
            else{
                if(dp[i-1][j] < dp[i][j-1]){
                    ans.push_back(str1[i-1]);
                    i--;
                }
                else{
                    ans.push_back(str2[j-1]);
                    j--;
                }
            }
        }
        while(i > 0){
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j > 0){
            ans.push_back(str2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
