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
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty())
            return {};
        vector<Interval> result;
        int i ;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        for(i = 1; i<intervals.size(); i++){
            if(intervals[i].start <= intervals[i-1].end && intervals[i].start >= intervals[i-1].start){
                Interval tmp;
                tmp.start = intervals[i-1].start;
                tmp.end = max(intervals[i-1].end, intervals[i].end);
                intervals[i] = tmp;
            }
            else
                result.push_back(intervals[i-1]);
        }
        result.push_back(intervals[i-1]);
        return result;
    }
};
