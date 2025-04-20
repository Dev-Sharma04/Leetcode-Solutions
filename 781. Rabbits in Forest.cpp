Question : There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.

Given the array answers, return the minimum number of rabbits that could be in the forest.



//Approach : Map
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        int n = answers.size();
        unordered_map<int,int> mpp;
        for(int i = 0; i < n ;i++){
            mpp[answers[i]]++;
        }
        for(auto &it : mpp){
            int x = it.first; // num
            int grpSize = x + 1; //num ka grp size kya hoga
            int cnt = it.second; // kitni br num aaya

            int grp = ceil((double)cnt/grpSize);// total kitne grp honge num ke

            ans += grp*grpSize;
        }
        return ans;
    }
};
