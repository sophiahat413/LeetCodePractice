class Solution {
public:
    /*bool compare(pair<int, int>& a, pair<int, int>& b){
        return a.first < b.first;
    }*/
    int find(int x, vector<int> &p){
        if(x != p[x])
            p[x] = find(p[x], p);
        return p[x];
    }
    void Union(int x, int y, vector<int> &r, vector<int> &p){
        int rX = find(x, p), rY = find(y, p);
        if(r[rX] < r[rY])
            p[rX] = rY;
        else if(r[rX] > r[rY])
            p[rY] = rX;
        else{
            p[rY] = rX;
            r[rX]++;
        }
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> parents(n);
        vector<int> rank(n, 0);
        set<int> isExist;
        int count = 0;
        iota(begin(parents), end(parents), 0);
        for(int i = 0; i<edges.size(); i++){
            Union(edges[i].first, edges[i].second, rank, parents);
        }
        for(int i = 0; i<n; i++){
            if(isExist.count(find(i, parents)) == 0){
                count++;
                isExist.insert(find(i, parents));
            }
        }
        return count;
    }
};
