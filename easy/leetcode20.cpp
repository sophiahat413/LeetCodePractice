class Solution {
public:
    bool isValid(string s) {
        int flag = 0;
        vector<char> tmp;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                tmp.push_back(s[i]);
            else if(s[i] == ')'){
                if(tmp.size() == 0)
                    flag = 1;
                else{
                    if(tmp[tmp.size()-1] == '[' || tmp[tmp.size()-1] == '{' )
                        flag = 1;
                    else if(tmp[tmp.size()-1] == '(')
                        tmp.erase(tmp.begin()+tmp.size()-1);
                }
            }
            else if(s[i] == '}'){
                if(tmp.size() == 0)
                    flag = 1;
                else{
                    if(tmp[tmp.size()-1] == '[' || tmp[tmp.size()-1] == '(' )
                        flag = 1;
                    else if(tmp[tmp.size()-1] == '{')
                        tmp.erase(tmp.begin()+tmp.size()-1);
                }
            }
            else if(s[i] == ']'){
                if(tmp.size() == 0)
                    flag = 1;
                else{
                    if(tmp[tmp.size()-1] == '{' || tmp[tmp.size()-1] == '(' )
                        flag = 1;
                    else if(tmp[tmp.size()-1] == '[')
                        tmp.erase(tmp.begin()+tmp.size()-1);
                }
            }
        }
        if(tmp.size() != 0 || flag == 1)
            return false;
        else
            return true;
    }
};
