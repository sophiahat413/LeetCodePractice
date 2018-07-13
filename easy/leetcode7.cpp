class Solution {
public:
    int reverse(int x) {
        int count = 0, negative = 0, digit;
        long int ans = 0;
        int check = pow(2, 31);
        if(x < 0){
            negative = 1;
            x = x * (-1);
            check = check * (-1);
        }
        else
            check -= 1;
            
        while(x > 0){
            digit = x % 10;
            ans = ans * 10 + digit;
            if(negative){
                long int tmp = ans * (-1);
                if(tmp < check )
                    return 0;
            }
            else
                if(ans > check)
                    return 0;
            count++;
            x = x / 10;
        }
        if(negative)
            ans = ans * (-1);
        return ans;
    }
};
