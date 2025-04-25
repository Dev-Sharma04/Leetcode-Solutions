Question : You are given a 0-indexed integer array nums, an integer modulo, and an integer k.

Your task is to find the count of subarrays that are interesting.

A subarray nums[l..r] is interesting if the following condition holds:

Let cnt be the number of indices i in the range [l, r] such that nums[i] % modulo == k. Then, cnt % modulo == k.
Return an integer denoting the count of interesting subarrays.

Note: A subarray is a contiguous non-empty sequence of elements within an array.

//Approach : Mod Properties
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        long long ans = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] %modulo == k){
                nums[i] = 1;
            }
            else nums[i] = 0;
        }
        
        unordered_map<int,long long> mpp; // remainder  -> cnt
        mpp[0] = 1;
        long long sum = 0; // sum equals cnt of elements whose mod with m = k 

        for(int i = 0; i < n; i++){
            sum += nums[i];

            int r1 = sum % modulo;
            int r2 = (r1 - k + modulo)%modulo;

            ans += mpp[r2];
            mpp[r1]++;
        }

        return ans;
    }
};
