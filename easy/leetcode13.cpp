class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int flagI = 0, flagX = 0, flagC = 0;
        for(int i = 0; i<s.length(); i++ ){
            if(s[i] == 'M'){
                if(flagC){
                    ans += 800;
                    flagC = 0;
                }
                else
                    ans += 1000;
            }
            else if(s[i] == 'D'){
                if(flagC){
                    ans += 300;
                    flagC = 0;
                }
                else
                    ans += 500;
            }
            else if(s[i] == 'C'){
                if(flagX){
                    ans += 80;
                    flagX = 0;
                }
                else{
                    ans += 100;
                    flagC = 1;
                }
            }
            else if(s[i] == 'L'){
                if(flagX){
                    ans += 30;
                    flagX = 0;
                }
                else
                    ans += 50;
            }
            else if(s[i] == 'X'){
                if(flagI){
                    ans += 8;
                    flagI = 0;
                }
                else{
                    ans += 10;
                    flagX = 1;
                }
            }
            else if(s[i] == 'V'){
                if(flagI){
                    ans += 3;
                    flagI = 0;
                }
                else
                    ans += 5;
            }
            else{
                ans += 1;
                flagI = 1;
            }
        }
        return ans;
    }
};
