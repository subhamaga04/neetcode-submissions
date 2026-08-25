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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){
            return a.start < b.start; 
        });
        int start_1 = intervals[0].start; 
        int end_1 = intervals[0].end; 

        for(int i = 1; i < intervals.size(); i++){
            if(end_1 > intervals[i].start){
                return false; 
            }else{
                start_1 = intervals[i].start; 
                end_1 = intervals[i].end; 
            }
        }

        return true; 
    }
};
