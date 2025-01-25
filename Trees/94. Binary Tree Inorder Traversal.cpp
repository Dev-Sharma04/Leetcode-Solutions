Inorder Traversal


//Approach : Using Recursion (DFS)
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
    void inorder(TreeNode* root, vector<int>&ans){
        if(!root)return;
        if(root->left)inorder(root->left,ans);
        ans.push_back(root->val);
        if(root->right)inorder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)return {};

        inorder(root,ans);
        return ans;
    }
};


//Approach : Using BFS 
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* node = root;
        vector<int> ans;
        
        while(true){
            if(node != NULL){
                s.push(node);
                node = node->left;
            }
            else{
                if(s.empty() == true)break;
                node = s.top();
                s.pop();
                ans.push_back(node->val);
                node = node -> right;
            }
        }
        return ans;
    }
};
