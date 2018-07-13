class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<char> ans;
        vector<vector<char>> zig;
        int count = 0, flag = 0, num = 0;;
        for(int i = 0; i<numRows; i++){
            vector<char> row;
            zig.push_back(row);
        }
        for(int i = 0; i<s.length(); i++){
            num++;
            if(count == numRows){
                if(numRows < 2)
                    count--;
                else
                    count -=2;
                flag = 1;
            }
            zig[count].push_back(s[i]);
            if(count == 0)
                flag = 0;
            if(flag == 0)
                count++;
            else if(flag == 1)
                count--;
        }
        for(int i = 0; i<zig.size(); i++){
            for(int q = 0; q<zig[i].size(); q++)
               ans.push_back(zig[i][q]);
        }
        string str;
        str.append(ans.begin(), ans.end());
        return str;
    }
};
