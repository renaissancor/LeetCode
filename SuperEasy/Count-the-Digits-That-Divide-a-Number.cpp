class Solution {
public:
    int countDigits(int num) {
        int ans = 0; 
        int cnt = num; 
        while (cnt) {
            int digit = cnt % 10; 
            if(num % digit == 0) ++ans; 
            cnt /= 10; 
        }
        return ans; 
    }
};