
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> parent(n);
        int group = n;
        for(int i = 0; i < n; i++)
            parent[i] = i;
        for(int i = 0; i < M.size(); i++){
            for(int q = i+1; q < M[i].size(); q++){
                if(M[i][q] == 1){
                    int lead1 = find(i, parent);
                    int lead2 = find(q, parent);
                    if(lead1 != lead2){
                        parent[lead1] = lead2;
                        group--;
                    }
                }
            }
        }
        return group;
    }
    int find(int i, vector<int> &parent){
        return (i == parent[i]) ? i : find(parent[i], parent);
    }
};
