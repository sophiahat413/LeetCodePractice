class Solution {
public:
    int bits(int n){
        int count = 0;
        while(n > 0){
            if(n % 2 != 0)
                count++;
            n /= 2;
        }
        return count;
    }
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0);
        for(int i = 0; i <= num; i++)
            result[i] = bits(i);
        return result;
    }
};
