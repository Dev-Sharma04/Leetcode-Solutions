Question : You are given a string word and a non-negative integer k.

Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

//Approach : SLiding Winodow
//T.C :O(n)
//S.C : O(n)

class Solution {
public:
    bool isVowel(char &ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ? true :false;
    }
    long long countOfSubstrings(string word, int k) {
        long long cnt = 0;
        int n = word.size();
        int i = 0, j = 0;
        map<char,int> mpp;
        int cons = 0;

        vector<int> nextConstIdx(n);
        int lastIdx = n;
        for(int i = n-1; i >= 0; i--){
                nextConstIdx[i] = lastIdx;
                if(!isVowel(word[i])) lastIdx = i;
        }

        while(j < n){
            char ch = word[j];
            if(isVowel(ch)){
                mpp[ch]++;
            }
            else cons++;

            while(i < n && cons > k){
                char ch = word[i];
                if(isVowel(ch)){
                    mpp[ch]--;
                    if(mpp[ch] == 0)mpp.erase(ch);
                }
                else cons--;  
                i++;
            }
            while(i < n && mpp.size() == 5 && cons == k){
                int idx = nextConstIdx[j];
                cnt += idx - j;
                if(isVowel(word[i])){
                    mpp[word[i]]--;
                    if(mpp[word[i]] == 0)mpp.erase(word[i]);
                }
                else cons--;
                i++;
            }
            j++;
        }
        return cnt;
    }
};
