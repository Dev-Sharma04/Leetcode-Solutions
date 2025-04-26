Question :You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array


//Approach : Maths
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        
        int minKPos = -1, maxKPos = -1, culpritIdx = -1;

        for(int i = 0; i < n; i++){
            if(nums[i] < minK || nums[i] > maxK)culpritIdx = i;
            if(nums[i] == minK)minKPos = i;
            if(nums[i] == maxK)maxKPos = i;

            int smaller = min(minKPos,maxKPos);
            int temp = smaller - culpritIdx;

            ans += temp <= 0 ? 0 : temp;
        }

        return ans;
    }
};
