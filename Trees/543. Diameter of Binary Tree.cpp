//Question : find height of binary tree :- The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

//Approach : Using recursion
//T.C : O(n)

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
    int height(TreeNode* root,int &ans){
        if(!root )return 0;
        int lh = height(root->left,ans);
        int rh = height(root->right,ans);
        ans = max(ans,lh+rh);
        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int ans = 0;
         height(root,ans);
        return ans;
        
    }
};
