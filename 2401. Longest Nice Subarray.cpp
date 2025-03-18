Question : You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.


  LEARNING :- While using sliding window to reduce the window size we use XOR and for increasing window we use AND.
  Eg :- Continuos element ka end zero aana chahie toh mask lekr chlo if & is 0  then use mask se | krdo aur jb window shrink krni ho toh mask ko ^ krdo num see


  //Approach : Brute Force (optimised using bit manipulation)
  //T.C : O(n^2)
  //S.C : O(1)

  class Solution {
public:
    
    int longestNiceSubarray(vector<int>& nums) {
        
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int mask = 0; // 000000 
            for(int j = i; j < n; j++){
                if((mask & nums[j]) != 0){
                    break;
                }
                ans = max(ans,j-i+1);
                mask = (mask | nums[j]);
            }
        }
        return ans;
    }
};

//Approach : Sliding Window
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        int ans = 0;
        int n = nums.size();
        int mask = 0;
        while(j < n){
            while((mask & nums[j]) != 0){
                mask ^= nums[i];
                i++;
            }
            ans = max(ans,j-i+1);
            mask |= nums[j];
            j++;
        }
        return ans;
    }
};
