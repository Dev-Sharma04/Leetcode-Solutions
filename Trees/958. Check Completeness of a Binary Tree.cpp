//Question : Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.


  //Approach : BFS
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
    
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        bool past = false;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr == NULL)past = true;
            else{
                if(past == true)return false;
                q.push(curr -> left);
                q.push(curr -> right);
            }
        }
        return true;
    }
};

//Approach : DFS
//T.C : O(n)
//S.C : O(n) system space

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
    bool dfs(TreeNode* root,int idx, int totalNodes){
        if(!root) return true ;

        if(idx > totalNodes)return false;

        return dfs(root->left,2*idx, totalNodes) && dfs(root->right,2*idx+1,totalNodes);
    }
    int countNodes(TreeNode* root){
        if(!root)return 0;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);
        int idx = 1;
        return dfs(root,1,totalNodes);
    }
};
  
