Question : Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.


//Approach : 
//T.C : O(n)
//S.C : O(n)


class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long cnt = 0;
        int i = 0;
        int n = nums.size();
        int j = 0;
        unordered_map<int,int> mpp;
        long long pairs = 0;
        while(j < n){
            pairs += mpp[nums[j]];
            mpp[nums[j]]++;

            while(j < n && pairs >= k){
                cnt += (n - j);
                mpp[nums[i]]--;
                pairs -=mpp[nums[i]];
                i++;  
            }
            j++;
        }
        return cnt;
    }
};
