Question : You are given an integer array nums consisting of 2 * n integers.

You need to divide nums into n pairs such that:

Each element belongs to exactly one pair.
The elements present in a pair are equal.
Return true if nums can be divided into n pairs, otherwise return false.




//Approach : Map
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> mpp;
        for(int i = 0;i < nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            int v = it.second;
            if(v % 2 != 0)return false;
        }
        return true;
    }
};
