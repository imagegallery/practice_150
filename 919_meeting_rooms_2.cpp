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
        vector<int> start;
        vector<int> end;

        for(auto iter: intervals){
            start.push_back(iter.start);
            end.push_back(iter.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int n = start.size();
        int i = 0, j = 0, count = 0, maxCount = 0;
        while(i < n){
            if(start[i] < end[j]){
                count ++;
                maxCount = max(maxCount, count);
                i++;
            }else{
                --count;
                j++;
            }
        }
        return maxCount;
    }
};
