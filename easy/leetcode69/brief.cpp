class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        //find the most sognificant bit
        int h = 0;
        while((long) (1 << h) * (long) (1 << h) <= x)
            h++;
        h--;
        //find the other bits
        int res = 1 << h;
        int b = h-1;
        while(b >= 0){
            if((long)(res | 1 << b) * (long)(res | 1 << b) <= x)
               res = res | 1 << b;
            b--;
        }
        return res;
    }
};
