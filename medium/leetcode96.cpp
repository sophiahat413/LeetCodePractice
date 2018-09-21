class Solution {
public:
    int numTrees(int n) {
        vector<int> combine(n+1, 0);
        combine[0] = 1;
        for(int i = 1; i <= n; i++){
            int t = 0;
            for(int j = 0; j < i; j++){
                t += combine[j] * combine[i-j-1];
            }
            combine[i] = t;
        }
        return combine[n];
    }
};
