Question : You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

Return the minimum time taken to repair all the cars.

Note: All the mechanics can repair the cars simultaneously.

  //Approach : binary search
  //T.C : O(nlogm)
  //S.C : O(1)
  
class Solution {
public:
    typedef long long ll;
    bool possible(vector<int>&ranks, int cars, ll time){
        ll cnt = 0;
        for(int i = 0; i < ranks.size(); i++){
            cnt += sqrt(time/ranks[i]);
        }
        return cnt >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll ans = 0;
        ll  l = 1;
        ll r = 1LL* *max_element(ranks.begin(),ranks.end()) *cars*cars;

        while(l <= r){
            ll mid = l + (r-l)/2;
            if(possible(ranks,cars,mid)){
                ans = mid;
                r = mid -1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
