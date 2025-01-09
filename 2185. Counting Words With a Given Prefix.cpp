//Question : You are given an array of strings words and a string pref.Return the number of strings in words that contain pref as a prefix.A prefix of a string s is any leading contiguous substring of s.

//Approach 1:using substring
//T.C :O(n)
//S.C :O(1)
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(int i = 0; i < words.size(); i++){
            if(words[i].substr(0,pref.size()) == pref)cnt++;
        }
        return cnt;
    }
};

//Approach 2: Using Trie
//T.C : O(n*l+m)
//S.C : O(n*l)

struct trieNode{
    trieNode* children[26];
    bool isEndOfWord;
};
trieNode* getNode(){
    trieNode* newNode = new trieNode();
    newNode -> isEndOfWord = false;
    for(int i = 0; i < 26; i++){
        newNode -> children[i] = NULL;
    }
    return newNode;
}
class Trie{
    public:
        trieNode* root;
        Trie(){
            root = getNode();
        }
        void insert(string word){
            trieNode* crawl = root;
            for(int i = 0; i < word.size(); i++){
                int idx = word[i] - 'a';
                if(crawl -> children[idx] == NULL){
                    crawl -> children[idx] = getNode();
                }
                crawl = crawl -> children[idx];
            }
            crawl -> isEndOfWord = true;
        }
        bool search(string prefix){
            trieNode* crawl = root;
            for(int i = 0; i < prefix.size(); i++){
                int idx = prefix[i] - 'a';
                if(crawl -> children[idx] == NULL)return false;
                crawl = crawl -> children[idx];
            }
            return true;
        }

};
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(int i = 0; i < words.size(); i++){
            Trie wordTrie;

            wordTrie.insert(words[i]);
            if(wordTrie.search(pref))cnt++;
        }
        return cnt;
    }
};
