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
    int solve(TreeNode* root, int mini, int maxi,int ans){
        if(!root)return ans;

        mini = min(root -> val, mini);
        maxi = max(root -> val, maxi);

        ans = abs(maxi - mini);

        return max(solve(root -> left,mini,maxi,ans), solve(root -> right,mini,maxi,ans));

    }
    int maxAncestorDiff(TreeNode* root) {
        return solve(root,INT_MAX,INT_MIN,0);
    }
};
