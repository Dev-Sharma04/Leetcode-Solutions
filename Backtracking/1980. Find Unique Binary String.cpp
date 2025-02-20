//Question  : Given an array of strings nums containing n unique binary strings each of length n, 
//return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

//Approach : Using Backtracking
//T.C : O(2^n)
//S.C : O(n)

class Solution {
public:
    void solve(string &s, set<string> &st ,int n, string &ans){
        
        if(s.size() == n){
            if(st.find(s) == st.end()){
                ans = s;
            }
            return;
        }
            for(char ch : {'0','1'}){
                s += ch;
                solve(s,st,n,ans);
                s.pop_back();
            }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st(nums.begin(),nums.end());
        int n = nums[0].size();
        string s = "";
        string ans = "";
        solve(s,st,n,ans);
        return ans;
    }
};

//Approach : Using Canter Diagonal Argument
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        for(int i = 0; i < nums.size(); i++){
            char ch = nums[i][i];
            ans += ch == '0' ? '1' : '0';
        }
        return ans;
    }
};
