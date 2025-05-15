#include <queue> 

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> que; 
        que.push(0); 

        while(!que.empty())
        {
            int idx = que.front(); 

            if(rooms[idx].empty()){
                rooms[idx].push_back(-1); 
            }

            if(rooms[idx][0] == -1){
                que.pop(); 
                continue; 
            }

            while(!rooms[idx].empty()){
                que.push(rooms[idx].back()); 
                rooms[idx].pop_back(); 
            }

            rooms[idx].push_back(-1); // Visited mark 
            

            que.pop(); 
        }

        for(int i=0; i<rooms.size(); ++i)
        {
            if(rooms[i].empty() || rooms[i][0] !=-1) return false; 
        }

        return true; 
        
        
    }
};