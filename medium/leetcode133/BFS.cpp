/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return NULL;
        else{
            UndirectedGraphNode * p1 = node;
            UndirectedGraphNode * p2 = new UndirectedGraphNode(node->label);
            map[node] = p2;
            queue<UndirectedGraphNode*> q;
            q.push(node);
            while(!q.empty()){
                p1 = q.front();
                p2 = map[p1];
                q.pop();
                for(int i = 0; i < p1->neighbors.size(); i++){
                    if(map.find(p1->neighbors[i]) == map.end()){
                        UndirectedGraphNode * copy = new UndirectedGraphNode(p1->neighbors[i]->label);
                        map[p1->neighbors[i]] = copy;
                        q.push(p1->neighbors[i]);
                    }
                    p2->neighbors.push_back(map[p1->neighbors[i]]);
                }
            }
            return map[node];
        }
    }
};


