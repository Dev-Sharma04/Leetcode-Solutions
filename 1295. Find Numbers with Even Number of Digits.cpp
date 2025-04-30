Question : Given an array nums of integers, return how many of them contain an even number of digits.

//Approach: Simulation
//T.C : O(nlogm)
//S.C : O(1)

class Solution {
public:
    bool check(int num){
        int cnt = 0;
        while(num){
            num/=10;
            cnt++;
        }
        return cnt % 2 == 0;
    }
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(check(nums[i]))cnt++;
        }
        return cnt;
    }
};

//Approach : Using log
//T.C : O(nlogm)
//S.C : O(1)

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(((int)log10(nums[i]) + 1 )% 2 == 0)cnt++;
        }
        return cnt;
    }
};
