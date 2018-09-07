
class Solution {
public:
    /**
     * @param time: the given time
     * @return: the next closest time
     */
    string nextClosestTime(string &time) {
        // write your code here
        int hour = 10 * (time[0] - '0') + time[1] - '0';
        int minte = 10 * (time[3] - '0') + time[4] - '0';
        int MIN = INT_MAX, hMIN = INT_MAX, hoMIN = INT_MAX, minMIN = INT_MAX;
        vector<int> permu;
        for(int i = 0; i<5; i++){
            if(i == 2)
                continue;
            for(int q = 0; q<5; q++){
                if(q == 2)
                    continue;
                int num = 10 * (time[i] - '0') + time[q] - '0';
                if(num != minte && num < 60)
                    minMIN = min(minMIN, num);
                if(num > minte && num < 60)
                    MIN = min(MIN, num);
                if(num > hour && num < 24)
                    hoMIN = min(hoMIN, num);
                if(num != hour && num < 24)
                    hMIN = min(hMIN, num);
                permu.push_back(num);
            }
        }
        if(MIN == INT_MAX){
            if(hoMIN == INT_MAX){
                if(hMIN == INT_MAX)
                    return time;
                time[0] = hMIN / 10 + '0';
                time[1] = hMIN % 10 + '0';
                time[3] = time[0];
                time[4] = time[1];
            }
            else{
                time[0] = hoMIN / 10 + '0';
                time[1] = hoMIN % 10 + '0';
                time[3] = minMIN / 10 + '0';
                time[4] = minMIN % 10 + '0';
            }
        }
        else{
            time[3] = MIN / 10 + '0';
            time[4] = MIN % 10 + '0';
        }
        return time;
    }
};
