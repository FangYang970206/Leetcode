/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
static int __ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) touch(it);
        else {
            if (cache.size() == _capacity) {
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key] = {value, used.begin()};
    }

private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> LLI;
    typedef unordered_map<int, LLI> HILLI;

    void touch(HILLI::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }

    int _capacity;
    LI used;
    HILLI cache;
};


class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        for (auto& p : time_map) 
            time_map[p.first] = p.second + 1;
        if (cache_map.find(key) != cache_map.end()){
            time_map[key] = 0;
            return cache_map[key];
        }else return -1;
    }
    
    void put(int key, int value) {
        if (cache_map.find(key) != cache_map.end()) {
            for (auto& p : time_map) 
                time_map[p.first] = p.second + 1;
            cache_map[key] = value;
            time_map[key] = 0;
            return;
        }
        if (size == cap) {
            int maxtime = 0, maxtime_key = 0;
            for (auto& p : time_map) {
                if (p.second > maxtime){
                    maxtime_key = p.first;
                    maxtime = p.second;
                }
                time_map[p.first] = p.second + 1;
            }
            cache_map.erase(maxtime_key);
            time_map.erase(maxtime_key);
            cache_map[key] = value;
            time_map[key] = 0;
        }else{
            for (auto& p : time_map) 
                time_map[p.first] = p.second + 1;
            cache_map[key] = value;
            time_map[key] = 0;
            size++;
        }
    }

private:
    int size;
    int cap;
    unordered_map<int, int> cache_map;
    unordered_map<int, int> time_map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

