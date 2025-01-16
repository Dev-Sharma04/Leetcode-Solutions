//Question : A 0-indexed array derived with length n is derived by computing the bitwise XOR (⊕) of adjacent values in a binary array original of length n.
// Specifically, for each index i in the range [0, n - 1]:
// If i = n - 1, then derived[i] = original[i] ⊕ original[0].
// Otherwise, derived[i] = original[i] ⊕ original[i + 1].
// Given an array derived, your task is to determine whether there exists a valid binary array original that could have formed derived.
// Return true if such an array exists or false otherwise.
// A binary array is an array containing only 0's and 1's


//Approach 1: Using xor property :- x^y = z then x^z = y && y^z = x
//T.C : O(2*n)
//S.C : O(n)
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        vector<int> original(n);
        original[0] = 0;
        for(int i = 0; i < n-1; i++){
            original[i+1] = original[i]^derived[i];
        }
        if(original[0] ^ original[n-1] == derived[n-1])return true;

        original[0] = 1;
        for(int i = 0; i < n-1; i++){
            original[i+1] = original[i]^derived[i];
        }
        if(original[0] ^ original[n-1] == derived[n-1])return true;
        return false;
    }
};



//Approach 2: Xor of all derived must be zero
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int val = 0;
        for(int i = 0; i < derived.size(); i++){
            val = val ^ derived[i];
        }
        return val == 0;
    }
};
