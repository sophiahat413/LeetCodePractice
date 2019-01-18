class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n, 0);
        stack<int> temp;
        for(int i = 0; i < T.size(); i++){
            if(!temp.empty()){
                while(T[temp.top()] < T[i]){
                    res[temp.top()] = i - temp.top();
                    temp.pop();
                    if(temp.size() == 0)
                        break;
                }
            }
            temp.push(i);
        }
        return res;
    }
};
