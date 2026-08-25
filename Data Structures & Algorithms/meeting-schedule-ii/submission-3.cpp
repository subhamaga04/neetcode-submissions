/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
   public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0; 
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){
            return a.start < b.start; 
        }); 

        priority_queue<int, vector<int>, greater<int>> min_heap; 

        for(auto &meeting : intervals){
            if(!min_heap.empty() && min_heap.top() <= meeting.start){
                min_heap.pop(); 
            }
            min_heap.push(meeting.end); 
        }

        return min_heap.size();


    }
};
