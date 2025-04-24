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
    vector<int> seq1; 
    vector<int> seq2; 
public:
    void find(TreeNode* iter, bool seq12) {
        if(iter->left == nullptr && iter->right == nullptr){
            if(seq12) {
                seq1.push_back(iter->val); 
            } else {
                seq2.push_back(iter->val); 
            }
        } else if(iter->left == nullptr) {
            find(iter->right, seq12); 
        } else if(iter->right == nullptr) {
            find(iter->left, seq12); 
        } else {
            find(iter->left, seq12); 
            find(iter->right, seq12); 
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        find(root1, true);
        find(root2, false); 

        if(seq1.size() == seq2.size()){
            for(size_t i=0; i<seq1.size(); i++){
                if(seq1[i] != seq2[i]){
                    return false; 
                }
            }
            return true; 
        }
        
        return false;  
    }
};