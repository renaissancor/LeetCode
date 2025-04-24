class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0; 
        int sub = 0; 
        int idx = 0; 

        for(int num: nums){
            sum += num; 
        }
        
        for(int num: nums){
            sum -= num; 
            if(sum == sub) return idx; 
            sub += num; 
            idx++; 
        }

        return -1;         
    }
};