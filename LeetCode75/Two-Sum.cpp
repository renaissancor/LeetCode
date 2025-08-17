class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const size_t n = nums.size(); 
        unordered_map<int, int> umap; 
        for(int i = 0; i < n; ++i) 
        {
            int numsj = target - nums[i]; 
            if (umap.count(numsj)) 
                return {umap[numsj], i}; 
            else umap.insert({nums[i], i}); 
        }
        return {-1, -1}; 
    }
};