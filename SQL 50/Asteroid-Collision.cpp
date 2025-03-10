class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;         
        
        for(int &itr: asteroids){
            if (itr > 0) {
                stk.push_back(itr); 
            } else { // if new asteroid itr < 0 
                bool loop = !stk.empty(); 
                while (!stk.empty() && stk.back()>0 && stk.back()<-itr){
                    stk.pop_back(); 
                }
                if(!stk.empty() && stk.back()==-itr){
                    stk.pop_back(); 
                } else if(stk.empty() || stk.back() < 0) {
                    stk.push_back(itr);
                }

            }
        }
        
        return stk;
    }
};