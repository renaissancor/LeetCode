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
    int ans; 
public:
    // dir true means node is parent's right node  
    // cnt increments how far zigzag starting point is 
    void zigzag(TreeNode* node, bool dir, int cnt) { 
        if(!node) return; 

        if(node->left){
            if(dir){ // right 
                zigzag(node->left, false, cnt+1); 
            } else {
                zigzag(node->left, false, 1); 
            }
        }

        if(node->right){
            if(dir){ // right 
                zigzag(node->right, true, 1); 
            } else {
                zigzag(node->right, true, cnt+1);
            }
        }

        if(cnt > ans) ans = cnt; 
    }

    int longestZigZag(TreeNode* root) {
        ans = 0; 

        zigzag(root->left, false, 1); 
        zigzag(root->right, true, 1); 
        
        return ans; 
    }
};