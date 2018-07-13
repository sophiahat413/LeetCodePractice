class Solution {
public:
    int myAtoi(string str) {
        int negative = 0, ans = 0, flag = 0, sign = 0;
        for(int i = 0; i<str.length(); i++){
            if(str[i] == ' '){
                if(flag == 0){   
                    if(sign)
                        return 0;
                    else
                        continue;
                }
                else
                    break;
            }
            else if(str[i] == '-'){
                if(flag)
                    break;
                else{
                    if(sign)
                        return 0;
                    negative = 1;
                    sign = 1;
                }
            }
            else if(str[i] == '+'){
                if(flag)
                    break;
                else{
                    if(sign)
                        return 0;
                    negative = 0;
                    sign = 1;
                }
            }
            else if(str[i] < 48 || str[i] > 57){
                if(flag == 0)
                    return 0;
                else
                    break;
            }
            else{
                long int tmp;
                if(negative){
                    tmp = ans * (-1);
                }
                else
                    tmp = ans;
                if((tmp > INT_MAX / 10) || ( (tmp == INT_MAX / 10) && ((str[i] - 48) > 7)))
                    return INT_MAX;
                if((tmp < INT_MIN / 10) || ( (tmp == INT_MIN / 10) && ((str[i] - 48) > 8)))
                    return INT_MIN;
                flag = 1;
                ans = ans * 10 + (str[i] - 48);
            }
        }
        if(negative)
            ans = ans * (-1);
        return ans;
    }
};
