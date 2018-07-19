class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        // put the first element
        vector<char> par;
        vector<char> left;
        vector<vector<char>> tmp;
        vector<vector<char>> lefts;
        vector<int> num_left;
        int count = 0;
        par.push_back('(');
        left.push_back('(');
        count++;
        tmp.push_back(par);
        lefts.push_back(left);
        num_left.push_back(count);
        
        for(int i = 1; i<n*2; i++){
            vector<vector<char>> set;
            vector<vector<char>> Nlefts;
            vector<int> Nnum_left;
            for(int q = 0; q<tmp.size(); q++){
                for(int j = 0; j<2; j++){
                    vector<char> copy = tmp[q];
                    vector<char> Fleft = lefts[q];
                    int Fcount = num_left[q];
                    if(j == 0){
                        if(Fleft.size() > 0){
                            copy.push_back(')');
                            Fleft.erase(Fleft.begin() + Fleft.size() - 1);
                        }
                        else
                            continue;
                    }
                    else{
                        if(Fleft.size() == n || Fcount == n)
                            continue;
                        copy.push_back('(');
                        Fleft.push_back('(');
                        Fcount++;
                    }
                    set.push_back(copy);
                    Nlefts.push_back(Fleft);
                    Nnum_left.push_back(Fcount);
                }
            }
            tmp = set;
            lefts = Nlefts;
            num_left = Nnum_left;
        }
        for(int i = 0; i<tmp.size(); i++){
            string set;
            set.append(tmp[i].begin(), tmp[i].end());
            ans.push_back(set);
        }
        return ans;
    }
};
