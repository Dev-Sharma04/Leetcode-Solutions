Question :Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.
If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
 


//Approach : DFS
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
    TreeNode* solve(TreeNode* root,int val, int depth, int curr){
        if(!root) return NULL;

        if(curr == depth-1){
            TreeNode* leftTemp = root -> left;
            TreeNode* rightTemp = root -> right;
            
            root -> left = new TreeNode(val);
            root -> right = new TreeNode(val);
            
            root -> left -> left = leftTemp;
            root -> right -> right = rightTemp;

            return root;
        }

        root -> left = solve(root-> left,val,depth,curr+1);
        root -> right = solve(root -> right , val, depth, curr + 1);

        return root;

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node -> left = root;
            return node;
        }
        int curr = 1;
        return solve(root,val,depth,curr);
    }
};
