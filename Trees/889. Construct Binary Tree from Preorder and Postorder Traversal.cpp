//Question : Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
//If there exist multiple answers, you can return any of them.


//Approach : Recursion
//T.C : O(n^2)
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
    TreeNode* solve(int preStart,int preEnd,int postStart, vector<int>& preorder, vector<int>& postorder ){
        if(preStart > preEnd)return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart == preEnd){
            return root;
        }
        int nextNode = preorder[preStart+1];
        int j = postStart;
        while(postorder[j] != nextNode){
            j++;
        }
        int num = j-postStart+1;

        root -> left = solve(preStart+1,preStart+num,postStart,preorder,postorder);
        root -> right = solve(preStart+num+1,preEnd,postStart+num,preorder,postorder);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return solve(0,preorder.size()-1,0,preorder,postorder);
    }
};


//Approach 2 : Optimised using map
//T.C : O(n)
//S.C : O(n)
