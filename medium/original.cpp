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
            if(s[pos] == '0'){
                ip += s[pos];
                cnt++;
                pos++;
                ip += '.';
                dfs(s, ip, res, pos, end, cnt);
                return;
            }
            num = num * 10 + s[pos] - '0';
            while(num < 256){
                ip += s[pos];
                cnt++;
                pos++;
                ip += '.';
                dfs(s, ip, res, pos, end, cnt);
                ip.pop_back();
                cnt--;
                num = num * 10 + s[pos] - '0';
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(s, "", res, 0, s.length(), 0);
        return res;
    }
};
