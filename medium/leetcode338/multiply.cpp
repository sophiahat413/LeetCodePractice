class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num+1, 0);
        bits[0] = 0;
        bits[1] = 1;
        bits[2] = 1;
        for(int i = 3; i<=num; i++){
            bits[i] = bits[i / 2] + i % 2;
        }
        return bits;
    }
};
