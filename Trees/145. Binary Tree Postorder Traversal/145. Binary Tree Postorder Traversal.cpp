//Question : Post order traversal


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
    void post(TreeNode* root, vector<int> &ans){
        if(!root)return;
        if(root->left)post(root->left,ans);
        if(root->right)post(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;

        post(root,ans);
        return ans;
    }
};

//Approach : Using Iterative Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1,s2;
        s1.push(root);
        vector<int> ans;
        if(!root)return {};
        while(!s1.empty()){
            TreeNode* curr = s1.top();
            s1.pop();
            s2.push(curr);
            if(curr -> left)s1.push(curr->left);
            if(curr -> right)s1.push(curr->right);
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};
