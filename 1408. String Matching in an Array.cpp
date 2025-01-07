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
