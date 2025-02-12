//Question : Give maximum depth of binary Tree

//Apporach : Using recursion
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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root)return 0;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                if(curr -> left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            ans++;
        }
        return ans;
    }
};

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
    int height(TreeNode* root){
        if(root == NULL)return 0;

        return 1 + max(height(root->left),height(root->right));
    }
    int maxDepth(TreeNode* root) {
        return height(root);
    }
};
