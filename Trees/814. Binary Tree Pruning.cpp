



//Approach : Brute
//T.C : O(n^2)
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
    bool isOnePresent(TreeNode *root){
        if(!root )return false;
        if(root -> val == 1)return true;

        return isOnePresent(root -> left) || isOnePresent(root -> right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)return NULL;

        if(!isOnePresent(root -> left))root->left = NULL;
        if(!isOnePresent(root -> right))root->right = NULL;

        pruneTree(root->left);
        pruneTree(root->right);

        if(!root -> left && !root -> right && root -> val == 0)return NULL;
        return root;
    }
};

//Approach : Optimal
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

    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)return NULL;

        root -> left = pruneTree(root->left);
        root ->right = pruneTree(root->right);
        if(!root -> left && !root -> right && root -> val == 0)return NULL;

        return (root);
    }
};
