Question : Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

//Approach : Brute - TLE
//T.C : O(n^2)
//S.C : O(1)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        int i = 0, j = 0;
        int n = nums.size();
        
        for( i = 0; i < n; i++){
            int sum = 0;
            for(j = i; j < n; j++){
                sum+=nums[j];
                if(sum %k == 0)cnt++;
            }
        }
        return cnt;
    }
};


//Approach : Using PrefixSum and property of modulo 
//T.C : O(n)
//S.C : O(k)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0;
        vector<int> remainderCnt(k,0);
        remainderCnt[0] = 1;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int remainder = sum % k;
            if(remainder < 0)remainder+=k;
            if(remainderCnt[remainder] > 0)ans += remainderCnt[remainder];
            remainderCnt[remainder]++;
        }
        return ans;
    }
};

