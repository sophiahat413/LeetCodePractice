class Solution {
public:
    string decodeString(string &s) {
        // write your code here
        string res  = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ']'){
                int back1 = res.length()-1;
                while(res[back1] != '[')
                    back1--;
                int back2 = back1;
                while(back2 > 0 && isdigit(res[back2-1])){
                    back2--;
                }
                string tmp = "";
                int n = stoi(res.substr(back2, back1 - back2));
                while(n > 0){
                    tmp += res.substr(back1+1);
                    n--;
                }
                res = res.substr(0, back2) + tmp;
            }
            else
                res += s[i];
        }
        return res;
    }
};
