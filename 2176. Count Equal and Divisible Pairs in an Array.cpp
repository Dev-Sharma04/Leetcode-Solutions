Question : Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) where 0 <= i < j < n, such that nums[i] == nums[j] and (i * j) is divisible by k.

//Approach : Brute
//T.C : O(n^2)
//S.C : O(1)

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n =nums.size();
        int cnt = 0;
        for(int i = 0; i  < n; i++){
            for(int j = i + 1 ; j < n ; j++){
                if(nums[i] == nums[j] && (i*j)%k == 0)cnt++;
            }
        }
        return cnt;
    }
};

//Approach : Optimal
//T.C : O(n* (log(k) + sqrt(k)))
//S.C : O(n)

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int,vector<int>> idxMap;

        for(int i = 0; i < n; i++){
            idxMap[nums[i]].push_back(i);
        }
        unordered_set<int> divisors; //div of k
        for(int i = 1; i*i <= k; i++){
            if(k % i == 0){
                divisors.insert(i);
                divisors.insert(k/i);
            }
            
        }

        for(auto& [num, indices] : idxMap){
            unordered_map<int,int> factorsMap;
            for(int i : indices){
                int GCD = gcd(i,k); //T.C : O(logk)
                int j = k/GCD;

                cnt += factorsMap[j];

                for(int f : divisors){
                    if(i%f == 0){
                        factorsMap[f]++;
                    }
                }
            }
        }
        return cnt;
    }
};
