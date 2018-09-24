class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool canStop(vector<vector<int>> &maze, int x, int y){
        if(x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] != 1)
            return false;
        return true;
    }
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // write your code 
        if(maze.empty())
            return false;
        queue<vector<int>> nodes;
        nodes.push(start);
        vector<vector<int>> directions({{1,0}, {-1,0}, {0,1}, {0,-1}});
        while(!nodes.empty()){
            vector<int> tmp = nodes.front();
            nodes.pop();
            int x = tmp[0], y = tmp[1], m, n;
            maze[x][y] = 2;
            for(int i = 0; i < directions.size(); i++){
                m = x, n = y;
                while(!canStop(maze, m, n)){
                    m += directions[i][0];
                    n += directions[i][1];
                }
                m -= directions[i][0];
                n -= directions[i][1];
                if(maze[m][n] != 2){
                    if(m == destination[0] && n == destination[1])
                        return true;
                    nodes.push({m, n});
                }
            }
        }
        return false;
    }
};
