class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_multiset<int>> edges(numCourses);
        vector<int> d(numCourses, 0);
        for(int i = 0; i<prerequisites.size(); i++){
            edges[prerequisites[i].second].insert(prerequisites[i].first);
            d[prerequisites[i].first]++;
        }
        // put head in a queue
        queue<int> q;
        vector<int> order;
        for(int i = 0; i<numCourses; i++){
            if(d[i] == 0){
                q.push(i);
                order.push_back(i);
            }
        }
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(auto it = edges[t].begin(); it != edges[t].end(); it++){
                d[*it]--;
                if(d[*it] == 0){
                    q.push(*it);
                    order.push_back(*it);
                }
            }
        }
        if(order.size() != numCourses)
            return {};
        return order;
    }
};
