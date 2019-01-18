/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if(intervals.empty()){
            res.push_back(newInterval);
            return res;
        }
        int idx = 0;
        while(idx < intervals.size() && intervals[idx].end < newInterval.start)
            res.push_back(intervals[idx++]);
        while(idx < intervals.size() && intervals[idx].start <= newInterval.end){
            newInterval.start = min(newInterval.start, intervals[idx].start);
            newInterval.end = max(newInterval.end, intervals[idx].end);
            idx++;
        }
        res.push_back(newInterval);
        while(idx < intervals.size())
            res.push_back(intervals[idx++]);
        return res;
    }
};
