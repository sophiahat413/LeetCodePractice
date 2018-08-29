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
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path 
     */
    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        // write your code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> record(n, vector<int>(m, INT_MAX));
        record[source.x][source.y] = 0;
        vector<vector<int>> d = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, 2}, {1, -2}, {2, 1}, {2, -1}};
        queue<Point> que;
        que.push(source);
        while(!que.empty()){
            Point head = que.front();
            que.pop();
            for(int i = 0; i < 8; i++){
                int x = head.x + d[i][0];
                int y = head.y + d[i][1];
                if(x>=0 && x<n && y>=0 && y<m && !grid[x][y] && record[head.x][head.y]+1 < record[x][y]){
                    record[x][y] = record[head.x][head.y]+1;
                    que.push(Point(x,y));
                }
            }   
        }
        if(record[destination.x][destination.y] == INT_MAX)
            return -1;
        return record[destination.x][destination.y];
    }
};
