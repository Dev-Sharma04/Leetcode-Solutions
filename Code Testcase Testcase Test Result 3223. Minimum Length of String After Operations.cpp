//Question : You are given a string s.
// You can perform the following process on s any number of times:
// Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
// Delete the closest character to the left of index i that is equal to s[i].
// Delete the closest character to the right of index i that is equal to s[i].
// Return the minimum length of the final string s that you can achieve.

//Approach1 : Storing in array and then traversing
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26,0);
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
            if(freq[s[i] - 'a'] == 3)freq[s[i]-'a']-=2;
        }
        int cnt = 0;
        
        for(int i = 0; i < 26; i++){
            cnt+=freq[i];
        }
        return  cnt;
    }
};


//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26,0);
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
            if(freq[s[i] - 'a'] == 3){
                freq[s[i]-'a']-=2;
                cnt+=2;
            }
        }

        return s.size() - cnt;
    }
};

//Approach1 : Using Modulo
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26,0);
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] ==0)continue;
            if(freq[i] % 2 == 0)ans+=2;
            else ans+=1;
        }
        return ans;
    }
};
