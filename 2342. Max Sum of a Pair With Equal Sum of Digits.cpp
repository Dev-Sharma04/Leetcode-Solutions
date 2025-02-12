//Question : You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
//Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.


//Approach : Using map - TLE
//T.C : O(n^2)
//S.C : O(n)

class Solution {
public:
    int sum(int x){
        int val= 0;
        while(x){
            int digit = x%10;
            val+=digit;
            x/=10;
        }
        return val;
    }
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int,int> digitSum; //nums[i] -> sumofdigit
        for(int i = 0; i < nums.size(); i++){
            int val = sum(nums[i]);
            for(auto it : digitSum){
                if(it.second == val){
                    ans = max(ans, nums[i]+it.first);
                }
            }
            digitSum[nums[i]] = val;

            
        }

        return ans;
    }
};


//Approach : Using map - MLE
//T.C : O(n^2)
//S.C : O(n^2)

class Solution {
public:
    int sum(int x){
        int val= 0;
        while(x){
            int digit = x%10;
            val+=digit;
            x/=10;
        }
        return val;
    }
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int,vector<int>> s2n; //sum -> nums[i]
        set<int> s;
        for(int i = 0; i < nums.size(); i++){
            int digitSum = sum(nums[i]);
            if(s.count(digitSum)){
                for(auto it : s2n){
                    if(it.first == digitSum ){
                        for(auto num : s2n[digitSum]){
                            ans = max(ans, nums[i]+num); 
                        }
                    }
                }
            }
            s.insert(digitSum);
            s2n[digitSum].push_back(nums[i]);

        }
        
        return ans;
    }
};

//Approach 3 : Using maps but optimising it
//T.C : O(n)
//S.C : O(n)
