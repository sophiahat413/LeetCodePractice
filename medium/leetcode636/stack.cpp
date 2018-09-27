class Solution {

struct Log{
    int id;
    string status;
    int time;
};
    
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<Log> st;
        for(string log: logs){
            string tmp1, tmp2, tmp3;
            stringstream ss(log);
            getline(ss, tmp1, ':');
            getline(ss, tmp2, ':');
            getline(ss, tmp3, ':');
            Log item = {stoi(tmp1), tmp2, stoi(tmp3)};
            if(item.status == "start")
                st.push(item);
            else{
                int timeAdd = item.time - st.top().time + 1;
                res[st.top().id] += timeAdd;
                st.pop();
                if(!st.empty()){
                    res[st.top().id] -= timeAdd;
                }
            }
        }
        return res;
    }
};
