class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> files;
        vector<vector<string>> res;
        for(int i = 0; i < paths.size(); i++){
            stringstream ss(paths[i]);
            string dir, s;
            getline(ss, dir, ' ');
            while(getline(ss, s, ' ')){
                string name = dir + '/' + s.substr(0, s.find('('));
                string content = s.substr(s.find('(')+1, s.find(')') - s.find('(')-1);
                files[content].push_back(name);
            }
        }
        for(unordered_map<string, vector<string>>::iterator it = files.begin(); it != files.end(); it++){      
            if(it->second.size() > 1)
                res.push_back(it->second);
        }
        return res;
    }
};
