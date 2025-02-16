// Question : Given an integer n, find a sequence that satisfies all of the following:
// The integer 1 occurs once in the sequence.
// Each integer between 2 and n occurs twice in the sequence.
// For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
// The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.
// Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.
// A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.


//Approach :Using backtracking and recursion
//T.C : O(n!)
//S.C : O(n)
class Solution {
public:
    bool solve(int idx, int n, vector<int>&ans,vector<bool>&used){
        if(idx >= ans.size())return true;
        if(ans[idx] != -1)return solve(idx+1,n,ans,used);


        for(int num = n; num >=  1; num--){
            if(used[num])continue;

            //try
            used[num] = true;
            ans[idx] = num;
            if(num == 1){
                if(solve(idx+1,n,ans,used))return true;
            }
            else{
                    int j = idx+num;
                    if(j < ans.size() && ans[j] == -1){
                        ans[j] = num;
                        if(solve(idx+1,n,ans,used))return true;
                        ans[j] = -1;
                    }
                }
            //undo
            used[num]= false;
            ans[idx] = -1;

        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        int sz = 2*n-1;
        vector<int> ans(sz,-1);
        vector<bool> used(n+1,false);
         solve(0,n,ans,used) ;
         return ans;
    }
};
