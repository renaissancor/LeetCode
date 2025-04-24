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
private: 
    vector<int> seq; 
public:
    void find(TreeNode* node) {
        if(node->left == nullptr && node->right == nullptr){
            seq.push_back(node->val); 
        } else if(node->left == nullptr) {
            find(node->right); 
        } else if(node->right == nullptr) {
            find(node->left); 
        } else {
            find(node->left); 
            find(node->right); 
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        find(root1); 
        size_t half = seq.size(); 
        find(root2); 

        if(half*2 == seq.size()) {
            for(size_t i=0; i<half; ++i){
                if(seq[i] != seq[i+half]){
                    return false; 
                }
            }
            return true; 
        }
        return false;  
    }
};