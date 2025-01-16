//Question : You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers.
// There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).
// Return the bitwise XOR of all integers in nums3.

//Approach 1: Brute Force (Gives TLE)
//T.C : O(n^2)
//S.C : O()

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> num;
        for(int i = 0; i < nums1.size(); i++){
            int val = 0;
            for(int j = 0; j < nums2.size(); j++){
                val = nums1[i]^nums2[j];
                num.push_back(val);
            }
            
            
        }
        int ans= 0;
        for(int i = 0; i < num.size(); i++){
            ans = ans ^ num[i];
        }
        return ans;
    }
};

//Approach 2: Understanding and simplifying the given constraints:- every number gets xor to itself n no. of times where n is the size of other array
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        for(int i = 0; i< nums1.size() ;i++){
            if(m % 2 != 0)ans^=nums1[i];
            
        }
        for(int i = 0; i < nums2.size(); i++){
            if(n%2 != 0)ans^=nums2[i];
        }
        return ans;
    }
};
