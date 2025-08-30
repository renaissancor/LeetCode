class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        const int n = nums.size(); 

        int l = 0; 
        int r = n - 1; 
        int i = n / 2; 

        while (l < i && i < r) {
            i = l + (r - l) / 2; 
            if (i == 0 || nums[i] > nums[i - 1]) {
                if (i == n - 1 || nums[i] > nums[i + 1])
                    return i; 
                l = i + 1; 
            } else {
                r = i - 1; 
            }
        }

        if (i == 0 || nums[i] > nums[i - 1]) {
            while (i != n - 1 && nums[i] < nums[i + 1]) ++i; 
            return i; 
        } else {
            while (i != 0 && nums[i] < nums[i - 1]) --i; 
            return i; 
        }
            

        return i; 
   }
};