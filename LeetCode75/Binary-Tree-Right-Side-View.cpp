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
    vector<int> ans; 

    void bfs(TreeNode *node, int depth){
        if(node == nullptr) return; 
        if(ans.size() == depth)
        {
            ans.push_back(node->val); 
        } else 
        {
            ans[depth] = node->val; 
        }
        
        bfs(node->left, depth+1); 
        bfs(node->right, depth+1); 
    }

    vector<int> rightSideView(TreeNode* root) {
        bfs(root, 0); 

        return ans;         
    }
};