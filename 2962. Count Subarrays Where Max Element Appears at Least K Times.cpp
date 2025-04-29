Question : You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

 



//Approach : Sliding Window
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        int i = 0, j = 0;
        int cnt = 0;
        int maxi = *max_element(nums.begin(),nums.end());
        while(j < n){
             if(nums[j] == maxi){
                cnt++;
            }
            while(cnt >= k && i <= j){
                ans += n - j;
                if(nums[i] == maxi){
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
