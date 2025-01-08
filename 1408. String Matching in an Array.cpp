//Question : Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.A substring is a contiguous sequence of characters within a string

//Approach 1: Brute Force
//T.c :O(n^2*m)
//S.C :O(1)
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i = 0; i < words.size();i++){
            for(int j = 0;j  < words.size(); j++){
                if(i == j ){
                    continue;
                }
                if( words[j].find(words[i]) != string::npos){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};


//Approach 2: KMP
//T.c :O(n^2*m)
//S.C :O(m)
class Solution {
public:
    void computeLPS(string pat, vector<int>&LPS){
        LPS[0] = 0;
        int M = pat.size();

        int len = 0;
        int i = 1;
        while(i < M){
            if(pat[i] == pat[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            else
                if(len != 0){
                    len = LPS[len-1];
                }
                else{
                    LPS[i] = 0;
                    i++;
                }
        }
    }
    bool checkKMP(string pat, string txt){
        int i = 0;
        int j = 0;
        int N = txt.size();
        int M = pat.size();

        vector<int> LPS(M,0);
        computeLPS(pat,LPS);

        while(i < N){
            if(txt[i] == pat[j]){
                i++;
                j++;
            }
            if(j == M){
                return true;
            }
            else{
                if(i < N && pat[j] != txt[i]){
                    if(j!= 0){
                        j = LPS[j-1];
                    }
                    else{
                        i++;
                    }
                }
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words.size(); j++){
                if(i == j)continue;

                if(checkKMP(words[i],words[j])){ //words[i] is pattern words[j] is txt
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
