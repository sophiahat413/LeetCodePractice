class Solution {
public:
    void dfs(string s, string ip, vector<string> &res, int pos, int end, int cnt){
        if(cnt == 4){
            if(pos == end)
                res.push_back(ip.substr(0, ip.length()-1));
            return;
        }
        else{
            int num = 0;
            for(int i = pos; i < pos + 3; i++){
                num = num * 10 + (s[i] - '0');
                if(num <= 255){
                    ip += s[i];
                    dfs(s, ip + '.', res, i+1, end, cnt+1);
                }
                if(num == 0)
                    break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(s, "", res, 0, s.length(), 0);
        return res;
    }
};
