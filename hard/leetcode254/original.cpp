class Solution {
vector<vector<int>> res;
public:
    void factors(int n, int f, vector<int> &group, int x){
        if(n == 1){
            res.push_back(group);
            return;
        }
        for(int i = f; i <= n; i++){
            if(i == x){
                break;
            }
            if(n % i == 0){
                group.push_back(i);
                factors(n/i, i, group, x);
                group.pop_back();
            }
        }
        
    }
    vector<vector<int>> getFactors(int n) {
        if(n <= 1)
            return {};
        vector<int> group;
        int x = n;
        factors(n, 2, group, x);
        return res;
    }
};
