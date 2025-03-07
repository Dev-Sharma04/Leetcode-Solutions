Question: Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= num1 < num2 <= right .
Both num1 and num2 are prime numbers.
num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

 



//Approach : Sieve of Erastothenisis
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    vector<bool> sieve(int right){
        vector<bool > prime(right+1,true);
        prime[0] = false;
        prime[1] = false;

        for(int i = 2; i*i <= right; i++){
            if(prime[i] == true){
                for(int j = 2; i*j <= right; j++){
                    prime[i*j] = false;
                }
            }
        }
        return prime;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime = sieve(right);

        vector<int> primes;
        int diff = INT_MAX;
        vector<int> res = {-1,-1};
        for(int i = left; i <= right ;i++){
            if(prime[i] == true){
                primes.push_back(i);
            }
        }
        for(int i = 1; i < primes.size(); i++){
            int d = primes[i]-primes[i-1];
            if(diff > d){
                diff = d;
                res = {primes[i-1],primes[i]};
            }
        }
        return res;
    }
};
