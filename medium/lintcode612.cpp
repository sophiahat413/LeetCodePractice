/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
vector<Point> result;
Point global_origin;
long long getDistance(Point a, Point b){
    return (a.x -b.x) * (a.x -b.x) + (a.y - b.y) * (a.y - b.y);
}
struct compare{
    bool operator()(const Point &a, const Point &b)const{
        int diff = getDistance(a, global_origin) - getDistance(b, global_origin);
        if(diff == 0)
            diff = a.x - b.x;
        if(diff == 0)
            diff = a.y - b.y;
        return diff < 0;
    }   
};
class Solution {

public:
    /**
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     *
     */
    vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
        // write your code here
        global_origin = Point(origin.x, origin.y);
        priority_queue<Point, vector<Point>, compare> queue;
        for(int i = 0; i<points.size(); i++){
            queue.push(points[i]);
            if(queue.size() > k)
                    queue.pop();
        }
        while(!queue.empty()){
            result.push_back(queue.top());
            queue.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
