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
    int count; 
    int target; 

    // Input vector array contains value from root at idx 0 to node now  
void getSums(TreeNode* node, vector<int> &arr){

        if(!node) return; 

        long sum = 0; 
        arr.push_back(node->val);

        for (int i=arr.size()-1; i>=0; --i){
            sum += arr[i]; 
            if(sum == target) ++count;             
        }

        getSums(node->left, arr); 
        getSums(node->right, arr); 

        arr.pop_back(); 
    } 

public:
    int pathSum(TreeNode* root, int targetSum) {
        count = 0; 
        target = targetSum; 
        vector<int> arr; 
        getSums(root, arr); 

        return count;         
    }
};