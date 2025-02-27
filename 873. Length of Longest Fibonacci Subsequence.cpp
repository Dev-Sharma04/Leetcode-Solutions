Question : A sequence x1, x2, ..., xn is Fibonacci-like if:

n >= 3
xi + xi+1 == xi+2 for all i + 2 <= n
Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.

A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].


//Approach : Rexursion
//T.C : O(n^3)
//S.C : O(n)

class Solution {
public:
    int solve(int j, int k , vector<int>&arr, unordered_map<int,int> &mpp){
        int target = arr[k] - arr[j];
        if(mpp.count(target) && mpp[target] < j){
            int i = mpp[target];
            return solve(i, j ,arr, mpp) + 1;
        }
        return 2;// 
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mpp;
        int ans = 0;
        for(int i = 0; i < n ; i++)mpp[arr[i]] = i;
        for(int k = n-1; k >= 0; k--){
            for(int j = k-1; j >= 0; j--){
                int len = solve(j,k,arr,mpp);
                if(len >=3 )ans = max(len,ans);
            }
        }
        return ans;
    }
};

//Approach : DP
//T.C : O(n^3)
//S.C : O(n)

class Solution {
public:
    int dp[1001][1001];
    int solve(int j, int k , vector<int>&arr, unordered_map<int,int> &mpp){
        int target = arr[k] - arr[j];
        if(dp[j][k] != -1)return dp[j][k];
        if(mpp.count(target) && mpp[target] < j){
            int i = mpp[target];
            return dp[j][k] = solve(i, j ,arr, mpp) + 1;
        }
        return dp[j][k] = 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        unordered_map<int,int> mpp;
        int ans = 0;
        for(int i = 0; i < n ; i++)mpp[arr[i]] = i;
        for(int k = n-1; k >= 0; k--){
            for(int j = k-1; j >= 0; j--){
                int len = solve(j,k,arr,mpp);
                if(len >=3 )ans = max(len,ans);
            }
        }
        return ans;
    }
};
