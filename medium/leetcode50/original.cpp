class Solution {
public:
    /*
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    
    double myPow(double x, int n) {
        // write your code here
        double res = 1;
        unsigned long long p = n;
        if(n < 0){
            p  = -n;
            x  = 1 / x;
        }
        else
            p = n;
        while(p){
            if(p & 0x01)
                res *= x;
            x *= x;
            p >>= 1;
        }
        return res;
    }
};
