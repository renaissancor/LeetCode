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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr; 
        if(root->val < key) {
            root->right = deleteNode(root->right, key); 
            return root; 
        }
        if(root->val > key) {
            root->left  = deleteNode(root->left , key); 
            return root; 
        }
        // When root-> key == key 

        if (root->left && root->right) {
            TreeNode* iter = root->right; 
            if(iter->left == nullptr) {
                iter->left = root->left; 
                delete root; 
                return iter; 
            }

            TreeNode* prev = root; 
            while(iter->left) {
                prev = iter; 
                iter = iter->left; 
            }
            root->val = iter->val; 

            prev->left = iter->right;  
            delete iter;               
            
            return root; 

        } else if (root->left) {
            TreeNode* temp = root->left; 
            delete root; 
            return temp; 
        } else if (root->right) {
            TreeNode* temp = root->right; 
            delete root; 
            return temp; 
        } else {
            delete root; 
            return nullptr; 
        }

        return root; 
    }
};