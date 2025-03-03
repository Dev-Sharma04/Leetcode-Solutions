
Quesdtion : You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.
More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. If i < j and both elements are smaller (or larger) than pivot, then pi < pj.
Return nums after the rearrangement.



//Approach : List
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        list<int> less;
        list<int> equal;
        list<int> greater;

        for (auto num : nums) {
            if (num < pivot) {
                less.push_back(num);
            } else if (num > pivot) {
                greater.push_back(num);
            } else {
                equal.push_back(num);
            }
        }

        less.insert(less.end(), equal.begin(), equal.end());
        less.insert(less.end(), greater.begin(), greater.end());

        vector<int> ans;
        for (auto num : less) {
            ans.push_back(num);
        }
        return ans;
    }
};
