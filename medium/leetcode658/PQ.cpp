class Solution {
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    struct myCompare{
        bool operator()(pair<int, int> p1, pair<int, int> p2){
            return p1.second < p2.second;
        }  
    };
    vector<int> findClosestElements(vector<int> &A, int k, int target) {
        // write your code here
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, myCompare> PQ;
        for(int i = 0; i < A.size(); i++){
            int dis = abs(A[i] - target);
            if(PQ.size() < k)
                PQ.push(make_pair(A[i], dis));
            else if(dis < PQ.top().second){
                PQ.pop();
                PQ.push(make_pair(A[i], dis));
            }
        }
        while(!PQ.empty()){
            res.push_back(PQ.top().first);
            PQ.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
