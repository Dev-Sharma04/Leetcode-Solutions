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
