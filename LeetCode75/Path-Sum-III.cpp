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
    // Input vector array contains value from root at idx 0 to node now  
    struct Context {
        int count = 0; 
        int target; 
        vector<int> arr; 
    }; 

    void getSums(TreeNode* node, Context &ctx){

        if(!node) return; 

        long sum = 0; 
        ctx.arr.push_back(node->val);

        for (int i=ctx.arr.size()-1; i>=0; --i){
            sum += ctx.arr[i]; 
            if(sum == ctx.target) ++(ctx.count); 
        }

        getSums(node->left , ctx); 
        getSums(node->right, ctx); 

        ctx.arr.pop_back(); 
    } 

public:
    int pathSum(TreeNode* root, int targetSum) {
        Context ctx;
        ctx.target = targetSum;
        getSums(root, ctx); 

        return ctx.count;         
    }
};