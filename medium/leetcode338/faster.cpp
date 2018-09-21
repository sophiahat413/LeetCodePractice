class Solution {
public:
    bool isPower(int n){
        return (n & n-1) == 0; 
    }
    vector<int> countBits(int num) {
        vector<int> bits(num+1, 0);
        bits[0] = 0;
        if(num >= 1)
            bits[1] = 1;
        int cur = 2, nearest = 2;
        while(cur <= num){
            nearest = isPower(cur) ? cur : nearest;
            bits[cur] = 1 + bits[cur - nearest];
            cur++;
        }
        return bits;
    }
};
