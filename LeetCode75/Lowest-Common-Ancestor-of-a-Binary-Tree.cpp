/**
 * Definition for a binary tree TreeNode.
 * struct TreeTreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeTreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root; 
        if(root == p || root == q) return root; 
        TreeNode* lTreeNode = lowestCommonAncestor(root->left , p, q); 
        TreeNode* rTreeNode = lowestCommonAncestor(root->right, p, q); 

        if(lTreeNode && rTreeNode) return root; 
        else if(!lTreeNode && !rTreeNode) return nullptr; 
        else return lTreeNode ? lTreeNode : rTreeNode; 
    }
};