
class Solution {
int mins[4] = {600, 60, 10, 1};
public:
    /**
     * @param time: the given time
     * @return: the next closest time
     */
    string nextClosestTime(string &time) {
        // write your code here
        size_t colon = time.find(':');
        int cur = 60 * stoi(time.substr(0, colon)) + stoi(time.substr(colon + 1));
        string next = "0000";
        for(int i = 1, d = 0; i <= 1440 && d < 4; i++){
            int min = (cur + i) % 1440;
            for(d = 0; d < 4; d++){
                next[d] = '0' + min / mins[d];
                min %= mins[d];
                if(time.find(next[d]) == string::npos)
                    break;
            }
        }
        return next.substr(0, 2) + ':' + next.substr(2, 2);
        
    }
};
