Question : Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper

  //Approach : Use of upper and lowerbound
  //T.C : O(nlog(n))
  //S.C : O(1)

  class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long cnt = 0;
        int n = nums.size();
    

        for(int i = 0; i < n; i++){
            int idx = lower_bound(nums.begin() + i+1 , nums.end(),lower - nums[i]) - nums.begin(); //gives the first element not less than lower -nums[i]
            int x = idx  ;
            idx = upper_bound(nums.begin() + i+1 , nums.end(),upper - nums[i]) - nums.begin(); //gives the first element greater than upper -nums[i]
            int y = idx  ;

            cnt+= y - x;
        }
        
        return cnt;
    }
};
