class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
     
    vector<int> merge(vector<int> & arr1, vector<int> arr2){
        vector<int> result;
        int i = 0, q = 0;
        while(i < arr1.size() && q < arr2.size()){
            if(arr1[i] >= arr2[q]){
                result.push_back(arr2[q]);
                q++;
            }
            else{
                result.push_back(arr1[i]);
                i++;
            }
        }
        while(i < arr1.size()){
            result.push_back(arr1[i]);
            i++;
        }
        while(q < arr2.size()){
            result.push_back(arr2[q]);
            q++;
        }
        return result;
    }
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        // write your code here
        if(arrays.empty())
            return {};
        while(arrays.size() > 1){
            vector<int> result = merge(arrays[0],arrays[1]);
            arrays.push_back(result);
            arrays.erase(arrays.begin());
            arrays.erase(arrays.begin());
        }
        return arrays.front();
    }
};
