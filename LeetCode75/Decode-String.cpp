class Solution {
public:
    string decodeString(string s) {

        stack<string> strStk;
        stack<int>    numStk; 
        string ans = \\; 
        int num = 0; 

        for (char &c : s) {
            if(isdigit(c)){
                num = num * 10 + ((int) c - 48); 
            } else if(c=='['){
                numStk.push(num); 
                num = 0; 
                strStk.push(ans); 
                ans = \\; 
            } else if(c==']'){
                int cnt = numStk.top(); 
                numStk.pop(); 

                string str = strStk.top(); 
                strStk.pop(); 
                string strs = \\; 
                
                for(int i=0; i<cnt; i++){
                    strs += ans; 
                } 

                ans = str + strs; 
            } else {
                ans.push_back(c); 
            }
        }

        return ans; 
    }
};