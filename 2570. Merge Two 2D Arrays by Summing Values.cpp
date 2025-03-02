Question : You are given two 2D integer arrays nums1 and nums2.

nums1[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
nums2[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
Each array contains unique ids and is sorted in ascending order by id.

Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions:

Only ids that appear in at least one of the two arrays should be included in the resulting array.
Each id should be included only once and its value should be the sum of the values of this id in the two arrays. If the id does not exist in one of the two arrays, then assume its value in that array to be 0.
Return the resulting array. The returned array must be sorted in ascending order by id.

 
//Approach : Using map and vector
//T.C : O(n)
//S.C : O(n+m)

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans(nums1.size()+nums2.size());
        unordered_map<int,int> mpp;
        for(int i = 0; i < nums1.size(); i++){
            mpp[nums1[i][0]] = nums1[i][1];
        }
        for(int i = 0; i < nums2.size(); i++){
            if(mpp.count(nums2[i][0])){
                mpp[nums2[i][0]] += nums2[i][1];
            }
            else mpp[nums2[i][0]] = nums2[i][1];
        }
        int i= 0;
        for(auto &it : mpp){
            int id = it.first;
            int val = it.second;
            vector<int> v = {id,val};
            ans[i] = v;
            i++;
        }
        while(ans.back().empty()){
            ans.pop_back();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
