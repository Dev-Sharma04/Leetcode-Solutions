Question : You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.

  //Approach : Sliding Window
  //T.C : O(n)
  //S.C : O(n)

  class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int>m1,m2;

        for(int i = 0; i < nums.size(); i++){
            m1[nums[i]]++;
        }
        int c = m1.size();
        int i = 0;
        int j = 0;
        int n = nums.size();

        while( j < n){
            m2[nums[j]]++;
            while(c == m2.size()){
                ans += n- j ;
                m2[nums[i]]--;
                if(m2[nums[i]] == 0)m2.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};
