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
           if(map.find(node) == map.end()){
               map[node] = new UndirectedGraphNode(node->label);
               for(int i = 0; i < node->neighbors.size(); i++)
                   map[node]->neighbors.push_back(cloneGraph(node->neighbors[i]));
           }
            return map[node];
        }
    }
};


