Question : You are given an integer array nums. You need to ensure that the elements in the array are distinct. To achieve this, you can perform the following operation any number of times:

Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all remaining elements.
Note that an empty array is considered to have distinct elements. Return the minimum number of operations needed to make the elements in the array distinct.



//Approach : Optimal
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> s;
        for(int i = n-1;i >= 0; i--){
            if(s.count(nums[i])){
                return ceil((i+1)/3.0);
            }
            s.insert(nums[i]);
        }
        return 0;
    }
};
