//Question : Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.

 

//Approach : Using loops
//T.C : O(n)
//S.C : O(1)


class Solution {
public:
    int mod = 1e9 +7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int val = 0;
        int oddcnt = 0;
        int evencnt = 1;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            val+=arr[i];
            if(val % 2 == 0){
                cnt += oddcnt;
                evencnt++;
            }
            else{
                cnt += evencnt;
                oddcnt++;
            }

        }

        return cnt%=mod;
    }
};
