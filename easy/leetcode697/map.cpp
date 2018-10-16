class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, vector<int>> mp;
        int len = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
            int tmp = mp[nums[i]].size();
            len = max(len, tmp);
        }
        int d = INT_MAX;
        for(map<int, vector<int>>::iterator it = mp.begin(); it != mp.end(); it++){
            if(it->second.size() == len){
                int n = it->second.size()-1;
                d = min(d, it->second[n] - it->second[0] + 1);
            }
        }
        return d;
    }
};
