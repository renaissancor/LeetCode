class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; 

        for(vector<int>::iterator num = nums.begin(); num != nums.end(); ++num) {
            pq.push(*num); 
        }
        
        int ans = pq.top(); 
        for(int i = 1; i < k; ++i) {
            pq.pop(); 
        }
        ans = pq.top(); 

        return ans; 
    }
};