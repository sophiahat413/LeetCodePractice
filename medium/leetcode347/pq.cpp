class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        //priority queue order by first element, the default is max heap
        priority_queue<pair<int, int>> Q;
        for(auto i : nums)
            mp[i]++;
        for(auto it = mp.begin(); it != mp.end(); it++){
            Q.push(make_pair(it->second, it->first));
            if(Q.size() > mp.size() - k){
                res.push_back(Q.top().second);
                Q.pop();
            }
        }
        return res;
    }
};
