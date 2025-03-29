Question : You are given an array nums of n positive integers and an integer k.

Initially, you start with a score of 1. You have to maximize your score by applying the following operation at most k times:

Choose any non-empty subarray nums[l, ..., r] that you haven't chosen previously.
Choose an element x of nums[l, ..., r] with the highest prime score. If multiple such elements exist, choose the one with the smallest index.
Multiply your score by x.
Here, nums[l, ..., r] denotes the subarray of nums starting at index l and ending at the index r, both ends being inclusive.

The prime score of an integer x is equal to the number of distinct prime factors of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3 * 5 * 5.

Return the maximum possible score after applying at most k operations.

Since the answer may be large, return it modulo 109 + 7.



//Approach: Using nextGreater and prevGreater and Sieve of Erastothenisis and binary Exponentiation
//T.C : O(n*log(n))
//S.C : O(n)

class Solution {
public:
    const int mod = 1e9 + 7;
    //binary Exponentiation
    long long findPower(long long a, long long b){
        if(b == 0)return 1;
        long long half = findPower(a,b/2);
        long long ans = (half*half)%mod;
        if(b % 2 == 1) ans = (ans*a)%mod;

        return ans;
    }

    //Sieve of Eratothenisis  :- finds prime 
    vector<int> getPrimes(int limit){
        vector<bool> isPrime(limit+1, true);
        vector<int> primes;

        for(int i = 2 ;i*i <= limit ; i++){
            if(isPrime[i]){
                for(int j = i*i; j<= limit ; j+=i){
                    isPrime[j] = false;
                }
            }
        }

        for(int i = 2; i <= limit; i++){
            if(isPrime[i])primes.push_back(i);
        }
        return primes;
    }

    vector<int> findPrimeScores(vector<int> &nums){
        int n = nums.size();
        vector<int> primeScores(n,0);

        int maxElement  = *max_element(nums.begin(),nums.end());
        vector<int> primes = getPrimes(maxElement);

        for(int i = 0; i < n; i++){
            int num  = nums[i];
            
            for(int prime : primes){
                if(prime*prime > num)break;

                if(num % prime != 0)continue;
                
                primeScores[i]++;
                while(num % prime == 0)num/= prime;
            }
            if(num > 1)primeScores[i]++;
        }
        return primeScores;
    }

    vector<int> findNextGreater(vector<int> &primeScores){
        int n = primeScores.size();

        vector<int> nextGreater(n);

        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && primeScores[st.top()] <= primeScores[i] ){
                st.pop();
            }
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nextGreater;
    }

    vector<int> findPrevGreater(vector<int> &primeScores){
        int n = primeScores.size();
        stack<int> st;
        vector<int> prevGreater(n);

        for(int i = 0 ; i < n; i++){
            while(!st.empty() && primeScores[st.top()] < primeScores[i]){
                st.pop();
            }

            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prevGreater;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        
        //find prime score
        vector<int> primeScores = findPrimeScores(nums);

        //populate nextgreater using mono stack
        vector<int> nextGreater = findNextGreater(primeScores);

        //populate prevGreaterEqual using mono stack
        vector<int> prevGreater = findPrevGreater(primeScores);

        //sort nums with their idx stored
        vector<long long> subarrays(n,0);

        for(int i = 0; i < n; i++){
            subarrays[i] = (long long)(nextGreater[i] -i) * (i - prevGreater[i] );
        }

        vector<pair<int,int>> sortedNums(n);
        for(int i = 0; i < n; i++){
            sortedNums[i] = {nums[i],i};
        }
        sort(sortedNums.begin(),sortedNums.end(),greater<> ());

        long long score = 1;
        int idx = 0; // starting from larget no.
        while(k > 0){
            auto [num,i] = sortedNums[idx];
            long long operations = min((long long)k,subarrays[i]);

            score = (score * findPower(num,operations))%mod;

            k = k - operations;
            idx++;
        }
        return score;
    }
};
