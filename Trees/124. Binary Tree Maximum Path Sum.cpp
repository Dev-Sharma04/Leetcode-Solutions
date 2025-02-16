//Question : A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any non-empty path.


//Approach : Using recursion

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
    int maxSum(TreeNode* root,int &ans){
        if(!root)return 0;

        int ls = max(0,maxSum(root->left,ans));
        int rs = max(0,maxSum(root->right,ans));
        
        ans = max(ans,ls+rs+root->val);
        return root->val + max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        int sum = INT_MIN;
        maxSum(root,sum);
        return sum ;
    }
};
