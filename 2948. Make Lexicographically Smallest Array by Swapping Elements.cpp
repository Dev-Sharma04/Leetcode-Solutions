//Question: You are given a 0-indexed array of positive integers nums and a positive integer limit.
// In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.
// Return the lexicographically smallest array that can be obtained by performing the operation any number of times.
// An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.




//Approach 1: Brute Force TLE
//T.C : O(n^3)
//S.C : O(1)

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        for(int i = 0; i < nums.size(); i++){
            int idx = i+1;
            while(idx < nums.size()){
                if(abs(nums[i] - nums[idx]) <= limit && nums[i] > nums[idx]){
                    swap(nums[i],nums[idx]);
                    idx = i+1;
                }
                else idx++;
            }
        }
         
        return nums;
    }
};


//Approach 1: Using sorting and map
//T.C : O(n*log(n))
//S.C : O(n)



class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> v = nums;
        sort(v.begin(),v.end());

        int grpNum = 0;
        unordered_map<int,int> numToGrp;
        numToGrp[v[0]] = grpNum;

        unordered_map<int,list<int>> grpToList;//list is implemented using linked list
        grpToList[grpNum].push_back(v[0]);

        for(int i = 1; i < nums.size(); i++){
            if(abs(v[i] - v[i-1]) > limit){
                grpNum+=1;
            }
            numToGrp[v[i]] = grpNum;
            grpToList[grpNum].push_back(v[i]);
        }
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int grp = numToGrp[num];
            ans[i] = *grpToList[grp].begin();;
            grpToList[grp].pop_front();
        }
        return ans;
    }
};
