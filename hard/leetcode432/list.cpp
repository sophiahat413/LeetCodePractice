class AllOne {

public:
    /** Initialize your data structure here. */
   // AllOne() {
        
   // }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto it = bucketofKey.find(key);
        //no key exist before
        if(it == bucketofKey.end()){
            //the first node is not the one time and there is no number 1 bucket
            if(buckets.begin()->value != 1 || buckets.empty()){
                buckets.push_front({1, {key}});
            }
            else
                buckets.front().keys.insert(key);
            bucketofKey[key] = buckets.begin();
            return;
        }
        //find the key move it to bigger number bucket
        auto lit = it->second;
        auto nit = next(lit);
        //insert the key to the next value(if it does not exist)
        if(nit == buckets.end() || nit->value != lit->value + 1){
            nit = buckets.insert(nit, {lit->value+1, {}});
        }
        nit->keys.insert(key);  
        //insert to the current bucket
        bucketofKey[key] = nit;
        lit->keys.erase(key);
        if(lit->keys.empty())
            buckets.erase(lit);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto it = bucketofKey.find(key);
        if(it == bucketofKey.end()) return;
        auto lit = it->second;
        if(lit->value > 1){
            auto nit = prev(lit);
            if(lit == buckets.begin() || nit->value != lit->value - 1)
                nit = buckets.insert(lit, {lit->value-1, {}});
            nit->keys.insert(key);
            bucketofKey[key] = nit;
        }
        else
            bucketofKey.erase(key);
        lit->keys.erase(key);
        if(lit->keys.empty())
            buckets.erase(lit);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }
private:
    struct bucket {int value; unordered_set<string> keys;};
    list<bucket> buckets;
    unordered_map<string, list<bucket>::iterator> bucketofKey;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
