class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> token;
        int res = 0, start = 0;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int tmp1 = token.top();
                token.pop();
                int tmp2 = token.top();
                token.pop();
                if(tokens[i] == "+")
                    token.push(tmp1 + tmp2);
                else if(tokens[i] == "-")
                    token.push(tmp2 - tmp1);
                else if(tokens[i] == "*")
                    token.push(tmp2 * tmp1);
                else if(tokens[i] == "/")
                    token.push(tmp2 / tmp1);
            }
            else
                token.push(stoi(tokens[i]));
        }
        return token.top();
    }
};
