//Question : You are given a string s.
// Your task is to remove all digits by doing this operation repeatedly:
// Delete the first digit and the closest non-digit character to its left.
// Return the resulting string after removing all digits.

//Approach  : Using stack
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        string ans = "";
        for(int i = 0; i< s.size(); i++){
            if(s[i] - 'a' < 0 || s[i]  - 'a'> 26 ){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }

        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
