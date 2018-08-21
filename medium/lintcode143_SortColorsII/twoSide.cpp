class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void swap(int *a, int *b){
        int t = *a;
        *a = *b;
        *b = t;
    }
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        int count = 0, left = 0, right = colors.size()-1;
        while(count <k){
            int cur = left;
            int minV = INT_MAX;
            int maxV = INT_MIN;
            for(int i = left; i<= right; i++){
                minV = std::min(colors[i], minV);
                maxV = std::max(colors[i], maxV);
            }
            while(cur <= right){
                if(colors[cur] == minV){
                    swap(&colors[cur], &colors[left]);
                    cur++;
                    left++;
                }
                else if(colors[cur] > minV && colors[cur] < maxV)
                    cur++;
                else{
                    swap(&colors[cur], &colors[right]);
                    right--;
                }
            }
            count+=2;
        }
    }
};
