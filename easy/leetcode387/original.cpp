class Solution {
public:
    int firstUniqChar(string s) {
        if(s.empty())
            return -1;
        map<char,int> map;
        int slow = 0;
        for(int i = 0; i< s.length(); i++){
            if(map.find(s[i]) == map.end()){
                map[s[i]] = 1; 
            }
            else{
                map[s[i]]++;
                if(s[i] == s[slow]){
                    slow++;
                    while(map.find(s[slow]) != map.end() && map[s[slow]] > 1){
                        slow++;
                    }
                    if(slow >= s.length())
                        return -1;
                }
            }
        }
        return slow;
    }
};
