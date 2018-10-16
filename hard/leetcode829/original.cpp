class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int count = 1;
        for(int k = 2; k * (k-1) < 2 * N; k++){
            if((N - (k * (k-1) / 2)) % k == 0)
                count++;
        }
        return count;
    }
};
