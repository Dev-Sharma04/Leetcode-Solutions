//Question : You are given two 0-indexed integer permutations A and B of length n.
// A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.
// Return the prefix common array of A and B.
// A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.


//Aproach 1: Using Set Theory
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int n = A.size();
        set<int> a,b;

        for(int i = 0; i < n; i++ ){
             a.insert(A[i]);
             b.insert(B[i]);
            
            int cnt = 0;
             for(auto it: a){
                if(b.find(it) != b.end()){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
