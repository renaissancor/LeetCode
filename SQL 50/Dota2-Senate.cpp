class Solution {
public:
    string predictPartyVictory(string senate) {
        
        int rcnt=0; 
        int dcnt=0; 

        queue<char> que; 
        
        for(char &senator: senate){
            // que.push(senator); 
            if(senator == 'R'){
                rcnt++; 
                que.push(senator); 
            } else if (senator == 'D'){
                dcnt++; 
                que.push(senator); 
            }
        }
        
        int rban=0; 
        int dban=0; 
        
        while(dcnt>0 && rcnt>0){
            int qsize = que.size(); 
            for(int i=0; i<qsize; i++){
                char now = que.front(); 
                que.pop(); 
                if(now == 'R'){
                    if(rban > 0){
                        rban--; 
                        rcnt--; 
                    } else {
                        dban++; 
                        que.push(now); 
                    }
                } else /* if(que.front() == \D\) */ {
                    if(dban > 0){
                        dban--; 
                        dcnt--; 
                    } else {
                        rban++; 
                        que.push(now); 
                    }
                }
            }
        }

        if(dcnt > 0){
            return \Dire\; 
        } else {
            return \Radiant\; 
        }
        
    }
};