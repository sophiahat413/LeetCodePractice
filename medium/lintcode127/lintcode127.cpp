/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    
    void dfs(DirectedGraphNode* cur, vector<DirectedGraphNode*> &ans, map<DirectedGraphNode*, int> &d, vector<DirectedGraphNode*> graph){
        ans.push_back(cur);
        d[cur]--;
        for(int i = 0; i<cur->neighbors.size(); i++){
            d[cur->neighbors[i]]--;
            if(d[cur->neighbors[i]] == 0)
                dfs(cur->neighbors[i], ans, d, graph);
        }
    }
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        map<DirectedGraphNode*, int> d;
        vector<DirectedGraphNode*> ans;
       /* for(int i = 0; i<graph.size(); i++)
            d[graph[i]] = 0;*/
        for(int i = 0; i<graph.size(); i++){
            for(int q = 0; q<graph[i]->neighbors.size(); q++){
                if(d.find(graph[i]->neighbors[q]) == d.end())
                    d[graph[i]->neighbors[q]] = 1;
                else
                    d[graph[i]->neighbors[q]] += 1;
            }
        }
        //cout<<d[graph[0]]<<endl;
        for(int i = 0; i<graph.size(); i++){
            if(d[graph[i]] == 0)
                dfs(graph[i], ans, d, graph);
        }
        return ans;
    }
};
