class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> ans1, ans2; 

        for(int num1:set1){
            if(set2.find(num1) == set2.end()){
                ans1.push_back(num1); 
            }
        }

        for(int num2:set2){
            if(set1.find(num2) == set1.end()){
                ans2.push_back(num2); 
            }
        }
                
        return {ans1, ans2}; 
    }
};