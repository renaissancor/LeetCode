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
    void isGood(TreeNode* node, int big, int &cnt){

        if(node->val >= big){
            big = node->val; 
            ++cnt;             
        }

        if(node->left){
            isGood(node->left, big, cnt);
        }

        if(node->right){
            isGood(node->right, big, cnt); 
        }
    }

public:
    int goodNodes(TreeNode* root) {
        int cnt = 0; 

        if(root){
            isGood(root, root->val, cnt); 
        }        

        return cnt;                
    }
};