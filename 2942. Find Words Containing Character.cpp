Question : You are given a 0-indexed array of strings words and a character x.

Return an array of indices representing the words that contain the character x.

Note that the returned array may be in any order.

  //Approach : simulation
  //T.C : O(n*m)
  //S.C : O(1)

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        int n = words.size();

        for(int i = 0; i < n; i++){
            for(int j = 0;  j < words[i].size(); j++){
                if(words[i][j] == x){
                    ans.push_back(i);
                    break;
                }
                
            }
        }
        return ans;
    }
};


  //Approach 2 : Using Lambda Capture
  //T.C : O(n)
  //S.C : O(1)
  
  class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        int n = words.size();

        auto lambda = [&x](char ch){ //lmabda capture [value which is needed to be accessed insde the function ] (parametrer which if have to be compared) {code base};
            return ch == x;
        };


        for(int i = 0; i < n; i++){
           if(any_of(words[i].begin(),words[i].end(),lambda))ans.push_back(i);
        }
        
        return ans;
    }
};

 
