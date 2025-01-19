



//Implementation Of Trie DataStructure
//T.C : O(n)
//S.C : O(n)


class Trie {
public:
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
    trieNode* root ;
    Trie() {   
        root =getNode();
    }
    
    void insert(string word) {
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
    
    bool search(string word) {
        trieNode* crawl = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(crawl -> children[idx] == NULL){
                return false;
            }
            crawl = crawl -> children[idx];
        }
        return crawl -> isEndOfWord ;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawl = root;
        int i = 0;
        for( i = 0; i < prefix.size(); i++){
            int idx = prefix[i] - 'a';
            if(crawl -> children[idx] == NULL){
                return false;
            }
            crawl = crawl -> children[idx];
        }
        if(i == prefix.length() )return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
