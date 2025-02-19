//Question :  A happy string is a string that:
// consists only of letters of the set ['a', 'b', 'c'].
// s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
// Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
// Return the kth string of this list or return an empty string if there are less than k happy strings of length n.


//Approach : BackTracking
//T.C : O(n*2^n)
//S.C : O(n*2^n)

class Solution {
public:
    void solve(string s, vector<string>&v, int n){
        if(s.size() == n){
            v.push_back(s);
            return;
        }
        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!s.empty() && s.back() == ch)continue;
            s.push_back(ch);  //do
            solve(s,v,n);//explore
            s.pop_back(); //return
        }
        return;
    }
    string getHappyString(int n, int k) {
        vector<string> v;   
        string s = "";
        solve(s,v,n);
        if(v.size() < k)return "";
        return v[k-1];
    }
};


//Approach : Optimised BackTracking
//T.C : O(n*2^n)
//S.C : O(n)


class Solution {
public:
    void solve(string s, string &ans, int n,int &k, int &cnt){
        if(s.size() == n ){
            cnt++;
            if(cnt == k){
                ans = s;
            }
            return ; 
        }
        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!s.empty() && s.back() == ch)continue;
            s.push_back(ch);  //do
            solve(s,ans,n,k,cnt);//explore
            s.pop_back(); //return
        }
        return;
    }
    string getHappyString(int n, int k) {
        string ans = "";
        int cnt = 0;   
        string s = "";
        solve(s,ans,n, k ,cnt);
        return ans;
    }
};
