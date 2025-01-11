//Question :Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

//Approach 1: Basic Hashmap 
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k)return false;
        vector<int> freq(26,0);
        for(char &ch : s){
            freq[ch-'a']++;
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] %2 != 0)cnt++;
            if(cnt > k )return false;
        }
        return true;
    }
};
