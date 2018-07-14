class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits.length() == 0)
            return ans;
        int store[8] = {3,3,3,3,3,4,3,4};
        vector<vector<char>> tmp;
        vector<char> copy;
        
        int index = 0;
        index = digits[0] - 48 - 2;
        //put the first element
        if(index < 6){
            for(int q = 0; q<store[index]; q++){
                vector<char> copy;    
                copy.push_back( 97+ 3*index + q);
                tmp.push_back(copy);
            }
        }
        else{
            for(int q = 0; q<store[index]; q++){
                vector<char> copy;    
                copy.push_back( 97+ 3* index + 1 + q);
                tmp.push_back(copy);
            }
        }
        for(int i = 1; i<digits.length(); i++){
            vector<vector<char>> set;
            index = digits[i] - 48 - 2;
            for(int j = 0; j<tmp.size(); j++){
                if(index < 6){
                    for(int q = 0; q<store[index]; q++){
                        vector<char> copy = tmp[j];    
                        copy.push_back( 97+ 3*index + q);
                        set.push_back(copy);
                    }
                }
                else{
                     for(int q = 0; q<store[index]; q++){
                        vector<char> copy = tmp[j];    
                        copy.push_back( 97+ 3* index + 1 + q);
                        set.push_back(copy);
                    }
                }
            }
            tmp = set;
        }
        for(int i = 0; i<tmp.size(); i++){
            string reg;
            reg.append(tmp[i].begin(), tmp[i].end());
            ans.push_back(reg);
        }
        return ans;
    }
};
