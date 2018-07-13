class Solution {
public:
    string intToRoman(int num) {
        vector<char> digit;
        string ans;
        int count = 0, tmp;
        while(num > 0){
            tmp = num;
            count = 0;
            if((tmp / 1000) > 0){
                count = num / 1000;
                for(int i = 0; i<count; i++)
                    digit.push_back('M');
                num -= 1000*count;
            }
            else if((tmp / 100) > 0){
                count = num / 100;
                num -= 100*count;
                if(count <= 4){
                    if(count == 4){
                        digit.push_back('C');
                        digit.push_back('D');
                    }
                    else{
                        for(int i = 0; i<count; i++)
                            digit.push_back('C');
                    }
                }
                else{
                    if(count == 9){
                        digit.push_back('C');
                        digit.push_back('M');
                    }
                    else{
                        digit.push_back('D');
                        count -= 5;
                        for(int i = 0; i<count; i++)
                            digit.push_back('C');
                    }
                }
            }
            else if((tmp / 10) > 0){
                count = num / 10;
                num -= 10*count;
                if(count <= 4){
                    if(count == 4){
                        digit.push_back('X');
                        digit.push_back('L');
                    }
                    else{
                        for(int i = 0; i<count; i++)
                            digit.push_back('X');
                    }
                }
                else{
                    if(count == 9){
                        digit.push_back('X');
                        digit.push_back('C');
                    }
                    else{
                        digit.push_back('L');
                        count -= 5;
                        for(int i = 0; i<count; i++)
                            digit.push_back('X');
                    }
                }
            }
            else{
                count = num;
                num -= count;
                if(count <= 4){
                    if(count == 4){
                        digit.push_back('I');
                        digit.push_back('V');
                    }
                    else{
                        for(int i=0; i<count; i++)
                            digit.push_back('I');
                    }
                }
                else{
                    if(count == 9){
                        digit.push_back('I');
                        digit.push_back('X');
                    }
                    else{
                        digit.push_back('V');
                        count -= 5;
                        for(int i = 0; i<count; i++)
                            digit.push_back('I');
                    }
                }
            }
        }
        ans.append(digit.begin(), digit.end());
        return ans;
    }
};
