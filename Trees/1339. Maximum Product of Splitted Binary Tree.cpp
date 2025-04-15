Question :Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.




//Approach : Simulation
//T.C : O(n)
//S.C : O(1)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int mod = 1e9+7;
    long totalSum = 0;
    long ans = 0;
    int solve(TreeNode* root){
        if(!root)return 0;

        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        long subTreeSum = root -> val + rightSum + leftSum;
        long s2 = totalSum - subTreeSum;

        ans = max((long )ans,(subTreeSum*s2));
        return subTreeSum;
    }
    
    int maxProduct(TreeNode* root) {
        if(!root)return 0;
        totalSum = solve(root);
        ans  = 0;
        solve(root);
        return ans%mod;
    }
};
