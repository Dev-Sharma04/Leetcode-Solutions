Question : You are given two integers n and maxValue, which are used to describe an ideal array.

A 0-indexed integer array arr of length n is considered ideal if the following conditions hold:

Every arr[i] is a value from 1 to maxValue, for 0 <= i < n.
Every arr[i] is divisible by arr[i - 1], for 0 < i < n.
Return the number of distinct ideal arrays of length n. Since the answer may be very large, return it modulo 109 + 7.

//Approach : Brute Force memoised
//T.C : O(n^maxVal)
//S.C : O(M*n)

class Solution {
public:
    const int mod = 1e9+7;
    vector<vector<int>> dp;
    int solve(int startVal,int cnt, int n, int maxVal){
        if(cnt == n)return 1;
        if(dp[startVal][cnt] != -1)return dp[startVal][cnt];
        long long ans = 0;
        for(int multiplier = 1; startVal*multiplier <= maxVal; multiplier++){
            ans = (ans + solve(startVal*multiplier, cnt+1, n ,maxVal))%mod;
        }
        return dp[startVal][cnt] = ans;
    }
    int idealArrays(int n, int maxValue) {
        long long ans = 0;
        dp.resize(maxValue+1,vector<int>(n+1,-1));
        for(int startVal = 1; startVal <= maxValue; startVal++){
            ans  = (ans + solve(startVal,1,n,maxValue))%mod;
        }
        return ans;
    }
};


//Approach - Using Maths (combinatorics) and DP
//T.C : O(maxVal * log(maxVal) + n)
//S.C : O(maxVal + n)
class Solution {
public:
    int M = 1e9+7;
    void findSets(int m, vector<int>& count, vector<vector<int>>& dp) {
        if(dp[m][1] != 0) {
            return;
        }

        dp[m][1] = 1;
        count[1]++;

        for(int div = 2; div <= m; div++) {
            if(m % div == 0) {
                findSets(m/div, count, dp);

                for(int len = 1; len < 15; len++) {
                    if(dp[m/div][len] != 0) {
                        dp[m][len+1] += dp[m/div][len];
                        count[len+1] += dp[m/div][len];
                    }
                }
            }
        }
    }

    int findPower(long long a, long long b) {
        if(b == 0)
            return 1;
        
        long long half = findPower(a, b/2);
        long long result = (half * half) % M;

        if(b%2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    int modularnCr(int n, int r, vector<long long>& fact) {
        if(r < 0 || r > n)
            return 0;
        
        long long b = (fact[r] * fact[n-r]) % M;
        return (fact[n] * findPower(b, M-2)) % M;
    }

    int idealArrays(int n, int maxVal) {
        vector<vector<int>> dp(maxVal+1, vector<int>(15, 0));
        vector<int> count(15, 0);

        //Find sets count
        for(int val = 1; val <= maxVal; val++) {
            findSets(val, count, dp);
        }

        //Precompute factorials
        vector<long long> fact(n+1, 1);
        for(int i = 2; i <= n; i++) {
            fact[i] = (fact[i-1] * i) % M;
        }

        long long result = 0;
        for(int len = 1; len < 15; len++) {
            if(n < len) {
                break;
            }
            if(count[len] != 0) {
                long long possibilities = modularnCr(n-1, len-1, fact);
                result = (result + (count[len] * possibilities)%M) % M;
            }
        }

        return (int)result;

    }
};
