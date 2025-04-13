Question : A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

  //Approach : simulation
  //T.C : O(log(n) + log(m))
  //S.C : O(1)

  class Solution {
public:
    int mod = 1e9+7;
    long long solve(int n , long long times){
        if(times  == 0)return 1;
        
        long long half = solve(n,times/2);
        long long ans = (half*half)%mod;

        return times % 2 == 1 ? (n*ans)%mod : ans;
    }
    int countGoodNumbers(long long n) {
        long long oddIdx = n/2;
        long long evenIdx = (n+1)/2;

        return (solve(5,evenIdx)%mod * solve(4,oddIdx)%mod)%mod;
    }
};
