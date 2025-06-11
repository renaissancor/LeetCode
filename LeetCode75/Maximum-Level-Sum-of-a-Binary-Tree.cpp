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
    int maxLevelSum(TreeNode* root) {

        int x = root->val; 
        int level  = 0; 
        int output = 1; 

        queue<TreeNode*> que; 
        que.push(root); 


        while(!que.empty()) {
            ++level; 
            size_t qsize = que.size(); 
            int xtemp = 0; 
            for(size_t i = 0; i < qsize; ++i) {
                TreeNode* node = que.front(); 
                que.pop(); 
                xtemp += node->val; 
                if(node->left ) que.push(node->left );
                if(node->right) que.push(node->right); 
            }

            if(xtemp > x) {
                output = level; 
                x = xtemp; 
            }
        }

        return output; 
    }
};