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
    int getDepth(TreeNode* node)
    {
        int ans = 1; 
        int l_cnt = 0, r_cnt = 0;

        if(node->left  != nullptr){
            l_cnt = getDepth(node->left ); 
        }

        if(node->right != nullptr){
            r_cnt = getDepth(node->right); 
        }

        ans += (l_cnt > r_cnt ? l_cnt : r_cnt); 

        return ans; 
    }

    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0; 
        return getDepth(root); 
    }
};