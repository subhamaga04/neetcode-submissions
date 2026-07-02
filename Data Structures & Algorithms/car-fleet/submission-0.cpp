class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars(position.size()); 
        for(int i = 0; i< position.size(); i++){
            cars[i] = {position[i], speed[i]}; 
        }
        sort(cars.rbegin(), cars.rend()); 
        int fleet = 0; 
        double current_leader = 0.0; 
        for(int i = 0; i<cars.size(); i++){
            double rt = (double)(target - cars[i].first)/ cars[i].second; 
            if(rt > current_leader){
                current_leader = rt; 
                fleet++; 
            }
        }

        return fleet; 
    }
};
