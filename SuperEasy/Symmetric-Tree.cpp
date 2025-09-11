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

    bool bfs(TreeNode* l, TreeNode* r) {
        if(l == nullptr && r == nullptr) return true; 
        if(l == nullptr) return false; 
        if(r == nullptr) return false; 
        if(l->val != r->val) return false; 

        if(bfs(l->right, r->left) == false) return false; 
        if(bfs(r->right, l->left) == false) return false; 

        return true; 

    }

    bool isSymmetric(TreeNode* root) {
        return bfs(root->left, root->right); 
    }
};