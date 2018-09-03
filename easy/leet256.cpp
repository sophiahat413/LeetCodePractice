class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int i;
        for(i = 1; i<costs.size(); i++){
           costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
           costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
           costs[i][2] += min(costs[i-1][0], costs[i-1][1]);
        }
        return (costs.size() == 0) ? 0 : min(costs[i-1][0], min(costs[i-1][1], costs[i-1][2]));
    }
};
