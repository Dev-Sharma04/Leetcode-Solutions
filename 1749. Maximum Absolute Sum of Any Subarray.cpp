Question : You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.

//Approach 1 : BruteForce (TLE)
//T.C : O(n^2)
//S.C : O(1)

  class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                ans = max(abs(sum),ans);
            }
        }
        return ans;
    }
};
//Approach 2: Kadane Algo => har idx pr ek sawal, tujhse shuru hou ya khud mai basa lu tujhe
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int currSubSum = nums[0];
        int maxSubSum = nums[0];    
        for(int i = 1; i < n; i++){
            currSubSum = max(nums[i],currSubSum+nums[i]);
            maxSubSum = max(currSubSum,maxSubSum);
        }
        currSubSum = nums[0];
        int minSubSum = nums[0];    
        for(int i = 1; i < n; i++){
            currSubSum = min(nums[i],currSubSum+nums[i]);
            minSubSum = min(currSubSum,minSubSum);
        }
        return max(abs(minSubSum),maxSubSum);
    }
};
