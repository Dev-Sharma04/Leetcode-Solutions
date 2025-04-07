Question : Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

  //Approach : Memoisation
  //T.C : O(n*x)
  //S.C : O(n)


  class Solution {
public:
    int dp[201][20001];
    bool solve(int idx, vector<int>&nums, int x){
        if(x == 0)return true;
        if(idx >= nums.size())return false;
        if(dp[idx][x] != -1)return dp[idx][x];
        bool take = false;
        if(nums[idx] <= x)take = solve(idx+1,nums,x-nums[idx]);
        bool notTake = solve(idx+1,nums,x);

        return dp[idx][x] = take || notTake;
        
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 != 0)return false;
        return solve(0,nums,sum/2);
        
    }
};
