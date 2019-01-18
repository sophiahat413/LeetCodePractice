class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> Q;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
        }
        for(unordered_map<char, int>::iterator it = mp.begin(); it != mp.end(); it++){
            Q.push(make_pair(it->second, it->first));
        }
        while(!Q.empty()){
            int num = Q.top().first;
            for(int i = 0; i < num; i++)
                res += Q.top().second;
            Q.pop();
        }
        return res; 
    }
};
