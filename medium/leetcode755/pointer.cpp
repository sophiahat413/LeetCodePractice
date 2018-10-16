class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
       for(int i = 0; i < V; i++){
           int pos = K;
           while(pos > 0 && heights[pos-1] <= heights[pos])
               pos--;
           while(pos < K && heights[pos] == heights[pos+1])
               pos++;
           if(pos == K){
               while(pos < heights.size()-1 && heights[pos+1] <= heights[pos])
                   pos++;
               while(pos > K && heights[pos] == heights[pos-1])
                   pos--;
           }
           heights[pos]++;
       }
       return heights;
    }
};
