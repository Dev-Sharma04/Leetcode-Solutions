//Question : Check if tree is balanced or not

//Approach : Using recursion
//T.C : O(n^2)

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
    int height(TreeNode*root){
        if(!root)return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;

        int lh = height(root->left);
        int rh = height(root->right);

        if(abs(lh-rh) > 1)return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || ! right)return false;
        return true;

    }
};


//Approach : Modifying height of binary tree code snippet
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
    int check(TreeNode* root){
        if(!root)return 0;

        int lh = check(root->left);
        int rh = check(root->right);
        if(lh == -1 || rh == -1)return -1;

        if(abs(lh-rh) > 1)return -1;
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;

        return check(root) != -1;
    }
};
