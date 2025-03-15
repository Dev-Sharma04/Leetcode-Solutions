Question : There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.

The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.

You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.

You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.

Return the minimum capability of the robber out of all the possible ways to steal at least k houses.

//Approach : DP :- Memoisatiom
//T.C : O(n*m) TLE
//S.C : O(n) 

class Solution {
public:
    
    int solve(int idx, vector<int>&nums, int k,vector<vector<int>> &dp){
        
        if(k == 0)return 0;
        if(idx >= nums.size())return INT_MAX;

        if(dp[idx][k] != -1)return dp[idx][k];
        //take
        int a = max(nums[idx],solve(idx+2,nums,k-1,dp));

        //not take
        int b = solve(idx+1,nums,k,dp);

        return dp[idx][k] = min(a,b);
    }
    
    int minCapability(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(k+1,-1));
        return solve(0,nums,k,dp);
    }
};

//Approach : Binary Search
//T.C : O(nlogm)
//S.C : O(1)

class Solution {
public:
    bool check(int v, vector<int>& nums, int k){
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= v){
                cnt++;
                i++;
            }
        }
        if(cnt >= k)return true;
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        int l = *min_element(nums.begin(),nums.end());
        int r = *max_element(nums.begin(),nums.end());

        
        int ans = INT_MAX;
        while(l <= r){
            int mid = l +(r-l)/2;

            if(check(mid,nums,k)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
