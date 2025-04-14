Question : Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

  //Approach : Simulation
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
