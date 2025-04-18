Question : The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.

  //approach : Simulation
  //T.C : O(n)
  //S.C : O(1)

  class Solution {
public:
    void solve(int n, string& ans){
        if(n == 1){
            ans = "1";
            return ;
        }

        solve(n-1,ans);
        int i = 0;
        int j = 0;
        string x = "";
        int cnt = 0;
        while(i < ans.size()){
            cnt = 0;
            while(j < ans.size() && ans[i] == ans[j]){
                cnt++;
                j++;
            }
            x += to_string(cnt);
            string num = to_string(ans[i]-48);
            x += num;
            i = j;
        }
        ans = x;
        return;
    }
    string countAndSay(int n) {
        string ans = "";
        solve(n,ans);
        return ans;
    }
};
