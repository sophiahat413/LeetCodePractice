class Solution {
public:
    int longestValidParentheses(string s) {
        int res = INT_MIN, cnt = 0, n = s.length();
        stack<int> stk;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')
                stk.push(i);
            else{
                if(!stk.empty()){
                    if(s[stk.top()] == '(')    stk.pop();
                    else    stk.push(i);
                }
                else stk.push(i);
            }
        }
        if(stk.empty()) return n;
        else{
            int a = n, b = 0;
            while(!stk.empty()){
                b = stk.top();
                stk.pop();
                res = max(res, a-b-1);
                a = b;
            }
            res = max(res, a);
        }
        return res;
    }
};
