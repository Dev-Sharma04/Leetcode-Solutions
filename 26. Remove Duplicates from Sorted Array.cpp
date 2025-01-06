//Question : Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
// Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
// Return k.

//Appraoch 1: Using set
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int i = 0; i <nums.size(); i++){
            s.insert(nums[i]);
        }
        int i = 0;
        for(auto it: s){
            nums[i++] = it;
        }
        return s.size();
    }
};
