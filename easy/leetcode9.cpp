class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else{
            int digit;
            long int rev = 0;
            int tmp = x;
            while(tmp > 0){
                digit = tmp % 10;
                rev = rev*10 + digit;
                if(rev > INT_MAX)
                    return false;
                tmp = tmp / 10;
            }
            if(rev == x)
                return true;
            else
                return false;
        }
    }
};
