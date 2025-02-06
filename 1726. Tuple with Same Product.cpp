//Question : Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.

//Approach : Optimised Brute Force - Sort array and take corner elements multiply them if and then traverse remaining and store the division and if we find that in elemets add 8 to answer and store it in set to
//avoid copies
//T.C : O(n^3)
//S.C : O(n)

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            for(int j = n-1; j >= i+1;j--){
                int product = nums[i]*nums[j];
                unordered_set<int> possibilities;

                for(int k = i+1;k < j; k++){
                    if(product%nums[k] == 0){
                        int dVal = product/nums[k];

                        if(possibilities.find(dVal) != possibilities.end()){
                            cnt+=8;
                        }

                        possibilities.insert(nums[k]);
                    }
                }
            }
        }
        return cnt;
    }
};
