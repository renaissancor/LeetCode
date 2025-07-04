class SmallestInfiniteSet {
    bool arr[1001]; 
    size_t idx = 1; // smallest idx 

public:
    SmallestInfiniteSet() {
        for(size_t i = 1; i < 1001; ++i) arr[i] = true; 
    }
    
    int popSmallest() {
        int ans = (int) idx; 
        arr[idx] = false; 

        for(size_t i = idx; i < 1001; ++i) {
            if(arr[i]) {
                idx = i;
                break; 
            }
        }
        return ans;         
    }
    
    void addBack(int num) {
        if(arr[num] == false) {
            arr[num] = true; 
            if(num <= idx) idx = num;
        }

    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */