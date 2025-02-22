//Question : We run a preorder depth-first search (DFS) on the root of a binary tree.
// At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
// If a node has only one child, that child is guaranteed to be the left child.
// Given the output traversal of this traversal, recover the tree and return its root.


//T.C : O(n)
//S.C : O(n) stack space


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
    int n;
    TreeNode* solve(int &i,const string &s, int depth){
        if(i >= n)return NULL;

        int j = i;
        while(j < n && s[j] == '-'){
            j++;
        }
        int dash = j-i;
        if(depth != dash)return NULL;
        i+=dash;
        int num = 0;
        while(i < n && isdigit(s[i])){
            num = (num*10) + (s[i]-'0');
            i++;
        }

        TreeNode* node = new TreeNode(num);
        node -> left = solve(i,s,depth+1);
        node -> right = solve(i,s,depth+1);


        return node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0;
        n = traversal.size();
        return solve(i,traversal,0);
    }
};
