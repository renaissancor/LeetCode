class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        const int n = nums.size(); 

        int l = 0; 
        int r = n - 1; 

        while (l < r) {
            int i = l + (r - l) / 2; 
            if(nums[i] > nums[i + 1]) r = i; 
            else l = i + 1;
        }
            

        return l; 
   }
};