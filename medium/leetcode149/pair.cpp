/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
private:
    int GCD(int a, int b){
        if(b == 0)
            return a;
        else
            return GCD(b, a%b);
    }
public:
    int maxPoints(vector<Point>& points) {
        //record different not steap line of vectors
        if(points.size() <= 2)
            return points.size();
        int res = 0;
        for(int i = 0; i < points.size(); i++){
            int count = 1, dup = 0, local = 0;
            map<pair<int,int>, int> lines;
            for(int q = i+1; q < points.size(); q++){
                if(points[i].x == points[q].x){
                    if(points[i].y == points[q].y)
                        dup++;
                    else
                        count++;
                }
                else{
                    int a = points[q].y - points[i].y;
                    int b = points[q].x - points[i].x;
                    int gcd = GCD(a, b);
                    a /= gcd;
                    b /= gcd;
                    if(lines.find(make_pair(a, b)) == lines.end())
                        lines[make_pair(a, b)] = 2;
                    else
                        lines[make_pair(a, b)]++;
                    local  = max(local, lines[make_pair(a, b)]);
                    cout<<"local: "<<local<<endl;
                }
            }
            local = max(local+dup, count+dup);
            res = max(res, local);
            cout<<res<<endl;
        }
        return res;
    }
};
