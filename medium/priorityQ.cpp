class Node {
public: 
    int row, col, val;
    Node(int r, int c, int v): row(r), col(c), val(v){};
    bool operator < (const Node &obj) const{
        return val > obj.val;
    }
};

class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        // write your code here
       vector<int> result;
        if(arrays.empty())
            return {};
        priority_queue<Node> queue;
        for(int i = 0; i<arrays.size(); i++){
            if(!arrays[i].empty())
                queue.push(Node(i, 0, arrays[i][0]));
        }
        while(!queue.empty()){
            Node tmp = queue.top();
            queue.pop();
            result.push_back(tmp.val);
            if(tmp.col + 1  < arrays[tmp.row].size())
                queue.push(Node(tmp.row, tmp.col+1, arrays[tmp.row][tmp.col+1]));
        }
        return result;
    }
};
