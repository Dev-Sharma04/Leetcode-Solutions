//Question :You are given a 0-indexed string array words.Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:

// isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix and a suffix of str2, and false otherwise.
// For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.
// Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.

//Approach1 : Simple Traversal
//T.C : O(n^2*m)
//S.C : O(1)
class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2){
        int i = 0;
        while(i < s1.size()){
            if(s1[i] != s2[i])return false;
            else i++;
        }
        
        int j = s2.size()-s1.size();
        i =0 ;
        while(j < s2.size()){
            if(s1[i] != s2[j])return false;
            else {
                i++;
                j++;
            }
        }

        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = i+1; j < words.size(); j++){
                if(isPrefixAndSuffix(words[i],words[j]))cnt++;
            }
        }
        return cnt;
    }
};


//Approach 2: Using find method
class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2){
        //prefix and suffix
        if(s2.find(s1) == 0 && s2.rfind(s1) == s2.size()-s1.size())return true;

        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = i+1; j < words.size(); j++){
                if(isPrefixAndSuffix(words[i],words[j]))cnt++;
            }
        }
        return cnt;
    }
};

//Approach 3: Using substring method
class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2){
        //prefix
        if(s2.substr(0,s1.size()) == s1 && s2.substr(s2.size()-s1.size()) == s1){
            return true;
        }

        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = i+1; j < words.size(); j++){
                if(isPrefixAndSuffix(words[i],words[j]))cnt++;
            }
        }
        return cnt;
    }
};

//Approach 4: Using Trie
//T.C : O(n^2*l)
//S.C : O(n*l);

struct trieNode{
    trieNode* children[26];
    bool isEndOfWord;
};
trieNode* getNode(){
    trieNode* newNode = new trieNode();
    newNode -> isEndOfWord = false;
    for(int i = 0; i < 26 ; i++){
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
            trieNode* pCrawl = root;
            for(int i = 0 ; i < word.size(); i++){
                int idx = word[i] - 'a';
                if(pCrawl -> children[idx] == NULL){
                    pCrawl->children[idx] = getNode();
                }
                pCrawl = pCrawl -> children[idx];
            }
            pCrawl -> isEndOfWord = true;
        }

        bool search(string prefix){
            trieNode* pCrawl = root;
            for(int i= 0; i < prefix.size(); i++){
                int idx = prefix[i] - 'a';
                if(pCrawl->children[idx] == NULL)return false;
                pCrawl = pCrawl->children[idx];
            }
            return true;
        }
};
class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2){
        //prefix
        if(s2.substr(0,s1.size()) == s1 && s2.substr(s2.size()-s1.size()) == s1){
            return true;
        }

        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        for(int j = 0; j < words.size(); j++){
            Trie prefixTrie;
            Trie suffixTrie;

            prefixTrie.insert(words[j]);
            string reversed =  words[j];
            reverse(reversed.begin(),reversed.end());
            suffixTrie.insert(reversed);
            
            for(int i = 0; i < j ; i++){
                if(words[i] > words[j])continue;

                string rev = words[i];
                reverse(rev.begin(),rev.end());
                if(prefixTrie.search(words[i])  && suffixTrie.search(rev))cnt++;
            }
        }
        return cnt;
    }
};
