//Question : Given a positive integer n, return the punishment number of n.
// The punishment number of n is defined as the sum of the squares of all integers i such that:
// 1 <= i <= n
// The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.


//Approach : Using Recursion
class Solution {
public:
    bool check(string s, int num, int i, int currSum){
        if(i == s.size())return currSum == num;
        if(currSum > num)return false;

        bool possible = false;
        for(int j = i; j < s.size(); j++){
            string x = s.substr(i,j-i+1);
            int val =stoi(x);

            possible = possible || check(s,num,j+1,currSum+val);

            if(possible == true)return true;

        }
        return possible;
    }
    int punishmentNumber(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            int val = i*i;
            if(check(to_string(i*i),i,0,0)){
                cnt+=(val);
            }
        }
        return cnt;
    }
};
