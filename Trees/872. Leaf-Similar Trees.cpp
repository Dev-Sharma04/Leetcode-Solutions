Question :Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.



//Approach : Simulation 
//T.C : O(n)
//S.C : O(1)

Note : You can always use string to store and match values it take less space and efficient so instead of vector we can use string.
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
    void solve(TreeNode* root, vector<int>&v){
        if(!root)return;

        if(root -> left == NULL && root -> right == NULL)v.push_back(root -> val);

        solve(root->left,v);
        solve(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        solve(root1,v1);
        vector<int> v2;
        solve(root2,v2);
        if(v1.size() != v2.size())return false;

        for(int i = 0; i < v1.size(); i++){
            if(v1[i] != v2[i])return false;
        }
        return true;
    }
};
