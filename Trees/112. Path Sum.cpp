Question : Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.


  //Appraoch : Traversal
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
    bool solve(TreeNode* root, int target){
        if(!root)return false;
        target -= root -> val;

        if(root -> left == NULL && root -> right == NULL && target == 0)return true;

        
        

        return solve(root -> left,target) || solve(root -> right,target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root )return false;
        
        return solve(root,targetSum);
        
    }
};
