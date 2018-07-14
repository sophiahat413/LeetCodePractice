//Time Limit Exceeded :/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for(int i = 0; i<height.size(); i++){
            if(height[i] == 0)
                continue;
            for(int q = i; q < height.size(); q++){
                if(height[q] == 0)
                    continue;
                int area = 0;
                if(height[i] >= height[q])
                    area = (q-i) * height[q];
                else if(height[i] < height[q])
                    area = (q-i) * height[i];
                if(area > max)
                    max = area;
            }
        }
        return max;
    }
};
