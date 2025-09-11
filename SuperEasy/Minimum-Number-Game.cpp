class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {

        sort(nums.begin(), nums.end()); 
        vector<int> arr; 

        int a, b; 
        for(int i = 0; i < nums.size(); ++i) {
            if(i % 2) {
                b = nums[i]; 
                arr.push_back(b); 
                arr.push_back(a); 
            } else {
                a = nums[i]; 
            }
        }

        return arr; 
    }
};