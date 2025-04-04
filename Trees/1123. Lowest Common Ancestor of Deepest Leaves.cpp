Question : Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.

                                OR
  865. Smallest Subtree with all the Deepest Nodes
  Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.


  //Approach : Using Recursion
  //T.C : O(n)
  //S.C : O(n)

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
    unordered_map<int,int> mpp;
    int maxD  = 0;

    void depth(TreeNode* root, int d){
        if(root == NULL)return ;

        mpp[root-> val] = d;
        maxD = max(d,maxD);
        depth(root->left,d+1);
        depth(root->right,d+1);

    }
    TreeNode* LCA(TreeNode* root){
        if(root == NULL)return NULL;
        
        if(mpp[root  -> val] == maxD )return root;

        TreeNode* l = LCA(root->left);
        TreeNode* r = LCA(root->right);

        if(l != NULL && r != NULL)return root;
        if(l != NULL)return l;
        
        return r;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root,0);

        return LCA(root);
    }
};
