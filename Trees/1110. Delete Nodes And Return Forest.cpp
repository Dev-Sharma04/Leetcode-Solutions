Question : Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

//Approach : DFS
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
    TreeNode* solve(TreeNode* root, unordered_set<int> &s,vector<TreeNode*> &ans){
        if(!root )return NULL;

        root -> left = solve(root -> left,s,ans);
        root -> right  = solve(root -> right, s,ans);

        if(s.count(root -> val)){
            if(root -> left != NULL)ans.push_back(root-> left);
            if(root -> right != NULL)ans.push_back(root-> right);

            return NULL;
        }
        else return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> s(begin(to_delete),end(to_delete));
        
        solve(root,s,ans);
        
        if(!s.count(root -> val)) ans.push_back(root);

        return ans;
    }
};
