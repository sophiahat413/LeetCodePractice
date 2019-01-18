class Solution {
private:
    struct mycompare{
        bool operator()(pair<int, int> p1, pair<int, int> p2){
            return p1.first + p1.second < p2.first + p2.second;
        }  
    };
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> PQ;
        for(int i = 0; i < min(k, (int)nums1.size()); i++){
            for(int q = 0; q < min(k, (int)nums2.size()); q++){
                if(PQ.size() < k){
                    PQ.push(make_pair(nums1[i], nums2[q]));
                }
                else if(nums1[i] + nums2[q] < PQ.top().first + PQ.top().second){
                    PQ.pop();
                    PQ.push(make_pair(nums1[i], nums2[q]));
                }
            }
        }
        while(!PQ.empty()){
            res.push_back(PQ.top());
            PQ.pop();
        }
        return res;
    }
};
