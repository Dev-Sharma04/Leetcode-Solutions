//Question : Given array,count no. of split in which left sum is greater than equal to right sum.

//Approach : Optimised Prefix Sum
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long  totalSum = 0;
        long long  leftSum = 0;
        for(auto it : nums){
            totalSum+=it;
        }
        int cnt = 0;
        for(int i = 0; i < nums.size()-1; i++){
            
            leftSum+=nums[i];
            totalSum-=nums[i];
            if(leftSum >= totalSum)cnt++;
            
        }
        return cnt;
    }
};
