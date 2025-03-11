Question : Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.


  //Approach : Sliding Window
  //T.C : O(n)
  //S.C : O(1) since mpp is of constant size (3)

  class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int n = s.size();
        map<char,int> mpp;
        int i = 0, j = 0;

        while(i < n && j < n){
            char ch = s[j];
            mpp[ch]++;
            while(mpp.size() == 3){
                cnt = cnt + (n-j);
                mpp[s[i]]--;
                if(mpp[s[i]] == 0)mpp.erase(s[i]);
                i++;
            }
            j++;
        }
        return cnt;
    }
};
