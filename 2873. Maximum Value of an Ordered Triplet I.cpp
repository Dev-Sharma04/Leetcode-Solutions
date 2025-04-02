Question : You are given a 0-indexed integer array nums.

Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.

The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

//Approach : Brute Force
//T.C : O(n^3)
//S.C : O (1)

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    maxi = max(maxi,(long long)(nums[i]-nums[j])*nums[k]);
                }
            }
        }
        return maxi < 0 ? 0 : maxi;
    }
};

//Approach : Better
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = INT_MIN;
        vector<long long> leftMax(n,0);
        vector<long long> rightMax(n,0);
        
        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i-1],(long long)nums[i-1]) ;
            cout<<leftMax[i];
        }
        
        for(int i = n-2; i >=  0; i--){
            rightMax[i] =   max(rightMax[i+1],(long long)nums[i+1]) ;
            cout<<rightMax[i];
        }

        for(int i = 1; i < n-1; i++){
            ans = max((leftMax[i] - nums[i])*rightMax[i] , ans);
        }
        return ans < 0 ? 0 : ans;
    }
};
