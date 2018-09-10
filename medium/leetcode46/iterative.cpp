class Solution {
private: 
    vector<vector<int>> result;
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permute(vector<int> &nums) {
        // write your code here
       vector<vector<int>> permutations(1, vector<int>());
       for(int i = 0; i<nums.size(); i++){
           vector<vector<int>> subpermutations(permutations);
           permutations.clear();
           for(int q = 0; q<subpermutations.size(); q++){
               
               for(int k = 0; k<= subpermutations[q].size(); k++){
                   vector<int> tmp(subpermutations[q]);
                   tmp.insert(tmp.begin()+k, nums[i]);
                   permutations.push_back(tmp);
               }
           }
       }
       return permutations;
    }
};
