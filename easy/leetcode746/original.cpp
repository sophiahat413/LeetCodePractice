class Solution {
public:
    int findCost(vector<int>& cost, vector<int>& lookup, int i){
        if(i == cost.size()-3)
            return cost[i] + min(cost[i+1], cost[i+2]);
        if(i == cost.size()-2 || i == cost.size()-1)
            return cost[i];
        if(lookup[i] != -1)
            return lookup[i];
        int c = cost[i] + min(findCost(cost, lookup, i+1), findCost(cost, lookup, i+2));
        lookup[i] = c;
        return c;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> lookup(cost.size(), -1);
        return  min(findCost(cost, lookup, 0), findCost(cost, lookup, 1));
    }
};
