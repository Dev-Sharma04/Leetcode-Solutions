Question :  The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums. 

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

//Approach : Simulation
//T.C : O(2^n*n)
//S.C : O (2^n*n)

class Solution {
public:
    void generate(int idx, vector<vector<int>> &v, vector<int>&nums, vector<int> ss){
        if(idx == nums.size()){
            v.push_back(ss);
            return;
        } 
        //pick
        ss.push_back(nums[idx]);
        generate(idx+1,v,nums,ss);

        ss.pop_back();
        generate(idx+1,v,nums,ss);
        
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> v;
        generate(0,v,nums,{});
        int ans = 0;
        for(int i = 0; i < v.size(); i++){
            int val = 0;
            for(auto it : v[i]){
                val^= it;
            }
            ans += val;
        }
        return ans;
    }
};


//Approach : Optimised BackTrack
//T.C : O(2^n)
//S.C : O(n)

class Solution {
public:
    int solve(int idx, vector<int>&nums, int val){
        if(idx == nums.size())return val;

        int pick =  solve(idx+1,nums,val^nums[idx]);
        int notPick = solve(idx+1,nums,val);

        return pick+notPick;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(0,nums,0);
    }
};

//Approach : Bit Manipulation
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans |= nums[i];
        }
        int n = nums.size()-1;
        while(n--){
            ans = ans << 1;
        }
        return ans;
    }
};
