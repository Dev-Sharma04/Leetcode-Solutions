//Question : Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.
// A substring is a contiguous sequence of characters in a string.

//Approach : Using string
//T.C : O(n^2)
//S.C : O(1)

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part) < s.length()){
            s.erase(s.find(part),part.length());
        }
         return s;
    }
};
