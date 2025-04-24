class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string tmp = ""; 

        size_t mid_size = str1.size() + str2.size(); 
        
        // Find GCD 
        size_t gcd_val = gcd(str1.size(), str2.size()); 
        
        for(size_t k=0; k < gcd_val; k++){
            if(str1[k]==str2[k]){
                tmp += str1[k]; 
            } else {
                return ""; 
            }
        }

        for(size_t k=0; k < str1.size(); k++){
            if(str1[k]!=tmp[k%gcd_val]) return ""; 
        }

        for(size_t k=0; k < str2.size(); k++){
            if(str2[k]!=tmp[k%gcd_val]) return ""; 
        }

        return tmp;
    }
};