Question : The score of an array is defined as the product of its sum and its length.

For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.

A subarray is a contiguous sequence of elements within an array.

 



//Approach : Sliding Window
//T.C : O(n)
//S.C : O(1)


class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        long long sum = 0;
        while(j < n){
            sum += nums[j];
            while(sum*(j-i+1) >= k ){
                sum-=nums[i];
                i++;
            }
            ans+= (j-i+1);
            j++;
        }
        return ans;
    }
};
