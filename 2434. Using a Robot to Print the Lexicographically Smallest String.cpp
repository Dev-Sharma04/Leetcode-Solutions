Question : You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:

Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
Return the lexicographically smallest string that can be written on the paper.


  //Approach : Understand and minchartoright array
  //T.C : O(n)
  //S.C : O(n)

  class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();

        vector<char> minCharToRight(n);
        minCharToRight[n-1] = s[n-1];
        for(int i = n-2; i >= 0; i--){
            minCharToRight[i] = min(minCharToRight[i+1] - 'a', s[i] - 'a') + 'a';
        }

        string t = "";
        string paper = "";
        
        int i = 0;
        while(i < n){
            t.push_back(s[i]);

            char minCh = i+1 < n ? minCharToRight[i+1] : s[i];
            while(!t.empty() && t.back() <= minCh){
                paper += t.back();
                t.pop_back();
            }
            i++;
        }
        while(!t.empty()){
            paper += t.back();
            t.pop_back();
        }
        return paper;
    }
};
