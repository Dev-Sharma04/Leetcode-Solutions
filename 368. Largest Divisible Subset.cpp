Question : Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

//Approach : Recursion TLE
//T.C : O(2^n)
//S.C : O(n)

class Solution {
public:
    void solve(int idx, vector<int>&nums, vector<int>&ans,vector<int>&temp,int prev ){
        if(idx >= nums.size()){
            if(temp.size() > ans.size()){
                ans = temp;
            }
            return;
        } 

        if(prev == -1 || nums[idx] % prev == 0){
            temp.push_back(nums[idx]);
            solve(idx+1,nums,ans,temp,nums[idx]);
            temp.pop_back();
        }
        solve(idx+1,nums,ans,temp,prev);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans, temp;
        sort(nums.begin(),nums.end());
        int prev = -1;
        solve(0,nums,ans, temp, prev);
        return ans;
    }
};

//Approach : Tabulation
//T.C : O(n^2)
//S.C : O(n)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1); //LIS wala hi h
        vector<int> ans;
        vector<int> prevIdx(n,-1);
        int maxLen = 1;
        int lastChosenIdx = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] ==  0){
                    if(dp[i] < dp[j]+1){
                        dp[i] =dp[j]+1;
                        prevIdx[i] = j;
                    }
                    if(dp[i] > maxLen){
                        maxLen = dp[i];
                        lastChosenIdx = i;
                    }
                }
            }
        }
        
        while(lastChosenIdx != -1){
            ans.push_back(nums[lastChosenIdx]);
            lastChosenIdx = prevIdx[lastChosenIdx];
        }
        return ans;
    }
};
