class Solution {
public:
    void swap(int *a, int *b){
        int t = *a;
        *a = *b;
        *b = t;
    }
    void sortColors(vector<int>& colors) {
        int l = 0, m = 0, r = colors.size()-1;
        while(m <= r){
            if(colors[m] == 0){
                swap(&colors[l], &colors[m]);
                l++;
                m++;
            }
            else if(colors[m] == 1){
                m++;
            }
            else if(colors[m] == 2){
                swap(&colors[m], &colors[r]);
                r--;
            }
        }
    }
};
