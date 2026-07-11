class Solution {
private: 
    priority_queue<int> pq;
public:
    int lastStoneWeight(vector<int>& stones) {
        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]); 
        }

        while(pq.size() > 1){
            int y = pq.top(); 
            pq.pop(); 
            int x = pq.top(); 
            pq.pop();

            if(y > x){
                pq.push(y-x); 
            }
        }

        if(!pq.empty()){
            return pq.top(); 
        }
        return 0; 
    }
};
