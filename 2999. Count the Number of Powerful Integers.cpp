Question : You are given three integers start, finish, and limit. You are also given a 0-indexed string s representing a positive integer.

A positive integer x is called powerful if it ends with s (in other words, s is a suffix of x) and each digit in x is at most limit.

Return the total number of powerful integers in the range [start..finish].

A string x is a suffix of a string y if and only if x is a substring of y that starts from some index (including 0) in y and extends to the index y.length - 1. For example, 25 is a suffix of 5125 whereas 512 is not.



//Approach : Simulation
//T.C : O(n*log(n))
//S.C : O(1)

class Solution {
public:
    long long solve(string& str, int limit , string &inputSuffix){
        if(str.length() < inputSuffix.length())return 0;

        long long cnt = 0;
        string trailString = str.substr(str.length() - inputSuffix.length());
        // "40001" - 5
        // "12" - 2
        // "400" - 3

        int remainingL = str.length() - inputSuffix.length();

        for(int i = 0; i < remainingL; i++){
            int digit = str[i]  -'0';

            if(limit >= digit) cnt += digit*pow(limit+1,remainingL - i - 1);
            else {
                cnt += pow(limit+1,remainingL-i);
                return cnt;
            }
        }
        if(trailString >= inputSuffix)cnt+=1;

        return cnt;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start-1);
        string finishStr = to_string(finish);

        return solve(finishStr,limit,s) - solve(startStr,limit,s);
    }
};
