//Question: Given a string s, find the length of the longest substring without repeating characters.

//Approach : Sliding Window
//T.C : O(n)
//S.c : O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        int sum = 0;
        int ans = INT_MAX;
        while(j < n){
            sum += nums[j];
            while(   sum >= target   ){
                ans = min(ans,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
