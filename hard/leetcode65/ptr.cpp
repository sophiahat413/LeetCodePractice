class Solution {
public:
    bool isNumber(string s) {
        int i = 0, cnt_dot = 0, cnt_num = 0, n = s.length();
        if(n == 0)  return false;
        while(s[i] == ' ')  i++;
        if(s[i] == '+' || s[i] == '-')  i++;
        while(isdigit(s[i]) || s[i] == '.')
            s[i++] == '.' ? cnt_dot++ : cnt_num++;
        if(cnt_dot > 1 || cnt_num < 1)  return false;
        if(s[i] == 'e'){
            i++;
            cnt_num = 0, cnt_dot = 0;
            if(s[i] == '+' || s[i] == '-')  i++;
            while(isdigit(s[i]) || s[i] == '.')
                s[i++] == '.' ? cnt_dot++ : cnt_num++;
            if(cnt_dot > 0 || cnt_num < 1)  return false;
        }
        while(s[i] == ' ')  i++;
        return i == n;
    }
};
