class KthLargest {
public:
    int value = 0; 
    priority_queue<int, vector<int>, greater<int>> pq; 
    
    KthLargest(int k, vector<int>& nums) {
        value = k; 
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]); 

            if(pq.size() > value){
                pq.pop(); 
            }
        }
    }
    
    int add(int val) {
        pq.push(val); 

        if(pq.size() > value) pq.pop(); 

        return pq.top(); 
    }
};
