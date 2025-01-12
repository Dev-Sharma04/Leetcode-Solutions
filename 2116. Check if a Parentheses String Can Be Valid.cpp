//Question :A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
// It is ().
// It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
// It can be written as (A), where A is a valid parentheses string.
// You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,
// If locked[i] is '1', you cannot change s[i].
// But if locked[i] is '0', you can change s[i] to either '(' or ')'.Return true if you can make s a valid parentheses string. Otherwise, return false.


//Approach : Using Stack
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2 != 0)return false;

        stack<int> open;
        stack<int> openClose;

        for(int i = 0; i < n ; i++){
            if(locked[i] == '0'){
                openClose.push(i);
            }
            else{
                if(s[i] == '('){
                    open.push(i);
                }
                else{
                    if(!open.empty() && open.top() < i)open.pop();
                    else if(!openClose.empty())openClose.pop();
                    else return false;
                }
            }
        }

        while(!open.empty() && !openClose.empty() && open.top() < openClose.top()){
            open.pop();
            openClose.pop();
        }
        
        return open.empty();
    }
};

//Approach 2: Using simple Traversa;
//Theory : Traverse krte wakt ek variable lelo open, agr '(' dikhe toh increase kro ya 0 dikhe locked mai toh increse kro otherwise decrease
// agr kbhi bhi open < 0 ho toh possible hi ni hai. Aise ek br left to right then right to left krna hai

//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int open = 0;
        if(s.size()%2 != 0)return false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || locked[i] == '0')open++;
            else open--;

            if(open < 0)return false;
        }
        
        open = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == ')' || locked[i] == '0')open++;
            else open--;
            
            if(open < 0)return false;
        }
        
        return true;
    }
};
