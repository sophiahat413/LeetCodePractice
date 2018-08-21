class Solution {
public:
    void swap(int *a, int *b){
        int t = *a;
        *a = *b;
        *b = t;
    }
    int partition(vector<int> &colors, int low, int high){
        int i = low-1, pivot = colors[high];
        for(int j = low; j<= high-1; j++){
            if(colors[j] <= pivot){
                i++;
                swap(&colors[i], &colors[j]);
            }
        }
        swap(&colors[i+1], &colors[high]);
        return i+1;
    }
    void qSort(vector<int> &colors, int low, int high){
        if(low >= high)
		return;
	if(low < high){
            int pivot = partition(colors, low, high);
            qSort(colors, low, pivot-1);
            qSort(colors, pivot+1, high);
        }
    }
    void sortColors(vector<int>& colors) {
         qSort(colors, 0, colors.size()-1);
    }
};
