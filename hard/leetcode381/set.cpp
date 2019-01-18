class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int, set<int>> mp;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        mp[val].insert(nums.size());
        nums.push_back(val);
        return mp[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(!mp.count(val))
            return false;
        int last = nums.back();
        int pos = *(mp[val].rbegin());
        mp[last].erase(*(mp[last].rbegin()));
        mp[last].insert(pos);
        nums[pos] = last;
        nums.pop_back();
        if(mp[val].size() > 1)
            mp[val].erase(pos);
        else
            mp.erase(val);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
