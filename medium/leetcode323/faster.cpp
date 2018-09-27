class Solution {
public:
    /*bool compare(pair<int, int>& a, pair<int, int>& b){
        return a.first < b.first;
    }*/
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> parents(n);
        int count = 0;
        iota(begin(parents), end(parents), 0);
        for(int i = 0; i<edges.size(); i++){
            int f = edges[i].first, e = edges[i].second;
            while(f != parents[f])
                f = parents[f];
            while(e != parents[e])
                e = parents[e];
            parents[e] = f;
        }
        for(int i = 0; i<n; i++){
           if(i == parents[i])
               count++;
        }
        return count;
    }
};
