class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> dic; 
        // first int key, second int value 

        for(int num: arr){
            dic[num]++; 
        }

        unordered_set<int> set; 
        for(auto &key_val : dic){
            if(set.count(key_val.second)>0){
                return false; 
            }

            set.insert(key_val.second);  
        }
        
        return true; 
    }
};