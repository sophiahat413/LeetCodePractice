class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> neighbors(n);
        for(int i = 0; i < edges.size(); i++){
            int f = edges[i].first, e = edges[i].second;
            neighbors[f].push_back(e);
            neighbors[e].push_back(f);
        }
        vector<bool> visited(n, false);
        if(hasCycle(neighbors, visited, 0, -1))
            return false;
        for(int i = 0; i < visited.size(); i++){
            if(!visited[i])
                return false;
        }
        return true;
    }
private:
    bool hasCycle(vector<vector<int>>& neighbors, vector<bool>& visited, int kid, int parent){
        if(visited[kid])
            return true;
        visited[kid] = true;
        for(auto nei: neighbors[kid]){
            if(nei != parent && hasCycle(neighbors, visited, nei, kid))
                return true;
        }
        return false;
    }
};
