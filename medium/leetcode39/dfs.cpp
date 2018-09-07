class Solution {
private:
    vector<vector<int>> result;
    
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    void dfs(vector<int> &num, vector<int> group, int sum, int cur, int target){
        if(cur >= num.size())
            return;
        if(sum + num[cur] == target){
            group.push_back(num[cur]);
            result.push_back(group);
            return;
        }
        if(sum + num[cur] > target)
            return;
        for(int i = cur; i<num.size(); i++){
            group.push_back(num[i]);
            sum += num[i];
            if(sum < target){
                int count = 0;
                while(num[i] == num[i+1])
                    i++;
                dfs(num, group, sum, i+1, target);
                while(sum + num[i] <= target){
                    group.push_back(num[i]);
                    sum += num[i];
                    count++;
                    if(sum == target){
                        result.push_back(group);
                        break;
                    }
                    dfs(num, group, sum, i+1, target);
                }
                for(int s = 0; s < count; s++){
                    sum -= num[i];
                    group.pop_back();
                }
            }
            else if(sum == target)
                result.push_back(group);
            sum -= group[group.size()-1];
            while(num[i] == group[group.size()-1])
                i++;
            i--;
            group.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &num, int target) {
        // write your code here
        if(num.empty())
            return {};
        sort(num.begin(), num.end());
        vector<int> group;
        dfs(num, group, 0, 0, target);
        return result;
    }
};
