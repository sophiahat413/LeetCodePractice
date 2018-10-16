/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    vector<int> res;
    int k = -1;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto i : nestedList){
            if(i.isInteger())
                res.push_back(i.getInteger());
            else
                build(i.getList());
        }
    }
    void build(const vector<NestedInteger> &nestedList){
        for(auto i : nestedList){
            if(i.isInteger())
                res.push_back(i.getInteger());
            else
                build(i.getList());
        }
    }
    int next() {
        k++;
        return res[k];
    }

    bool hasNext() {
        if(k == -1)
            return res.size() > 0;
        if(k + 1 < res.size())
            return true;
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
