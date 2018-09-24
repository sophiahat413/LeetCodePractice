class Solution {
public:
      string construct(string &s, int &cur, string &res){
        cout<<cur<<endl;
        if(cur >= s.length())
            return res;
        if(s[cur] == ']'){
            return res;
        }
        if(s[cur] >= '0' && s[cur] <= '9'){
            int tmp = s[cur] - '0';
            while(s[cur+1] >= '0' && s[cur+1] <= '9'){
                tmp = tmp * 10 + s[cur+1] - '0';
                cur++;
            }
            cur += 2;
            string newString;
            newString = construct(s, cur, newString);
            for(int i = 0; i< tmp; i++)
                res += newString;
            cur += 1;
            return construct(s, cur, res);
        }
        if((s[cur] >= 'a' && s[cur] <= 'z') || (s[cur] >= 'A' && cur <= 'Z')){
            res += s[cur];
            cur += 1;
            return construct(s, cur, res);
        }
    }
    
    string decodeString(string &s) {
        // write your code here
        string res;
        int cur = 0;
        return construct(s, cur, res);
    }
};
