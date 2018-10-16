class Solution {
private: 
    string IPv6c = "0123456789ABCDEFabcdef";
    bool isIPv4(string &block){
        int num = 0;
        if(block.length() > 0 && block.length() <=3){
            for(int i = 0; i < block.length(); i++){
                char c = block[i];
                if(!isalnum(c) || i == 0 && c == '0' && block.length() > 1)
                    return false;
                num = num * 10 + c - '0';
            }
            return num <= 255;
        }
        return false;
    }
    bool isIPv6(string &block){
        if(block.length() > 0 && block.length() <= 4){
            for(int i = 0; i < block.length(); i++){
                char c = block[i];
                if(IPv6c.find(c) == string::npos)
                    return false;
            }
            return true;
        }
        return false;
    }
public:
    string validIPAddress(string IP) {
        string res[3] = {"Neither", "IPv4", "IPv6"};
        stringstream ss(IP);
        string block;
        if(IP.substr(0,4).find('.') != string::npos){
            for(int i = 0; i < 4; i++){
                if(!getline(ss, block, '.') || !isIPv4(block))
                    return res[0];
            }
            return ss.eof() ? res[1] : res[0];
        }
        else if(IP.substr(0,5).find(':') != string::npos){
            for(int i = 0; i < 8; i++){
                if(!getline(ss, block, ':') || !isIPv6(block))
                    return res[0];
            }
            return ss.eof() ? res[2] : res[0];
        }
       return res[0];
    }
};
