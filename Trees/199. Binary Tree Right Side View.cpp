//Question : Given tree give the right side view of tree.


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

//Approach : Using BFS(Level Order Traversal)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int n = q.size();
            vector<int> v;
            TreeNode* curr = NULL;
            while(n--){
                curr = q.front();
                q.pop();                
                if(curr -> left != NULL)q.push(curr -> left);
                if(curr -> right != NULL )q.push(curr -> right);
            }
            ans.push_back(curr -> val);
        }
        return ans;
    }
};

//Approach : Using BFS (with vector)
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        vector<vector<int>> v;
        while(!q.empty()){
            int n = q.size();
            vector<int> lvl;
            while(n--){
                TreeNode* curr = q.front();
                q.pop();
                lvl.push_back(curr-> val);
                if(curr -> left)q.push(curr -> left);
                if(curr -> right)q.push(curr -> right);
                
            }
            v.push_back(lvl);
        }
        for(int i = 0; i < v.size(); i++){
            ans.push_back(v[i].back());
        }
        return ans;
    }
};

//Approach : Using DFS 
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
    void revPreOrder(TreeNode* root, int lvl, vector<int>& ans){
        if(root == NULL)return;
        
        if(ans.size() < lvl)ans.push_back(root->val);

        revPreOrder(root->right,lvl+1,ans);
        revPreOrder(root->left,lvl+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        revPreOrder(root,1,ans);

        return ans;
    }
};


