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
    void rainbowSort(vector<int> &colors, int Fcolor, int Lcolor, int left, int right){
        if(Fcolor == Lcolor)
            return;
        if(left >= right)
            return;
        int l = left, r = right, Mcolor = (Fcolor + Lcolor) / 2;
        while(l <= r){
            while(l <= r && colors[l] <= Mcolor)
                l++;
            while(l <= r && colors[r] > Mcolor)
                r--;
            if(l <= r){
                swap(&colors[l], &colors[r]);
                l++;
                r--;
            }
        }
        rainbowSort(colors, Fcolor, Mcolor, left, r);
        rainbowSort(colors, Mcolor+1, Lcolor, l, right);
    }
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        rainbowSort(colors, 1, k, 0, colors.size()-1);
    }
};
