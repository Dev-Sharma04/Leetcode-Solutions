Question : An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.

You are given a 0-indexed integer array nums of length n with one dominant element.

You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

0 <= i < n - 1
nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

  //Approach : Simulation using map
  //T.C : O(n)
  //S.C : O(2*n)

  class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for(int i = 0; i < n; i++){
            m2[nums[i]]++;
        }

        for(int i = 0; i < n; i++){
            int num = nums[i];

            m1[num]++;
            m2[num]--;

            int n1 = i+1;
            int n2 = n-i-1;

            if(m1[num]*2 > n1 && m2[num]*2 > n2){
                return i;
            }


  //Approach : Using Majority Element Algorithm (Bayer- Moore)
  //T.C : O(n)
  //S.C : O(1)

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        //Boyer-Moore Algorithm :- Finds out majority element in the array
        int maj = -1;
        int freq = 0;
        for(int i = 0; i < n; i++){
            if(freq == 0){
                maj = nums[i];
                freq = 1;
            }
            else{
                if(maj != nums[i]){
                    freq--;
                }
                else freq++;
            }
        }

        int majCnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]== maj)majCnt++;
        }

        freq = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == maj){
                freq++;
            }
            int remainingCnt = majCnt - freq;
            int n1 = i+1;
            int n2 = n-i-1;
            if(freq*2 > n1 && remainingCnt*2 > n2)return i; 
        }
        return -1;
    }
};
        }
        return -1;
    }
};
