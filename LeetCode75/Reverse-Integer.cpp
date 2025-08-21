class Solution {
public:
    int reverse(int x) {
        
        bool negative = (x < 0); 
        int y = (x % 10); 
        if (negative) y *= -1; 
        x /= 10; 

        while (x != 0) 
        {
            if (y <= 214748364) y = y * 10; 
                else return 0; 
            if (negative){
                if (y > -2147483648 + (x % 10)) y -= (x % 10); 
                else return 0; 
            } else {
                if (y <  2147483647 - (x % 10)) y += (x % 10); 
                else return 0; 
            }
            x /= 10; 
        }

        if (negative) y *= -1; 

        return y;
    }
};