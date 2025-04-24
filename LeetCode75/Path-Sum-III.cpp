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
void getSums(TreeNode* node, vector<int> &arr, int &count, const int &target){

        if(!node) return; 

        long sum = 0; 
        arr.push_back(node->val);

        for (int i=arr.size()-1; i>=0; --i){
            sum += arr[i]; 
            if(sum == target) ++count;             
        }

        getSums(node->left , arr, count, target); 
        getSums(node->right, arr, count, target); 

        arr.pop_back(); 
    } 

public:
    int pathSum(TreeNode* root, int targetSum) {
        const int target = targetSum; 
        int count = 0; 
        vector<int> arr; 
        getSums(root, arr, count, target); 

        return count;         
    }
};