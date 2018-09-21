class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0, max = 0;
        for(int i = 1; i < prices.size(); i++){
            result += prices[i] - prices[i-1];
            if(result < 0) 
                result = 0;
            if(result > max)
                max = result;
        }
        return max;
    }
};
