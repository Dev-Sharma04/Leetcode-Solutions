PreOrder Traversal 


//Approach : Using recursion (DFS)
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
    private:
    void solve(TreeNode* root, vector<int>&ans){
        if(root == NULL){
            return;
        }

        if(root->left) solve(root->left,ans);
        if(root->right)solve(root->right,ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};


//Approach : Using stack (BFS)
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)return {};
        stack<TreeNode*> s;
        s.push(root);
        vector<int> ans;
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            ans.push_back(node-> val);
            if(node -> right)s.push(node->right);
            if(node -> left)s.push(node->left);
        }
        return ans;
    }
};
