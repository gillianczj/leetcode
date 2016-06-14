struct cacheNode {
    int key;
    int value;
    cacheNode(int k, int v): key(k), value(v) {}
};
class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    int get(int key) {
        if(cacheMap.count(key)) {
            auto it = cacheMap[key];
            cacheList.splice(cacheList.begin(), cacheList, it);
            return cacheList.begin()->value;
        }else {
            return -1;
        }
    }
    void set(int key, int value) {
        if(cacheMap.count(key)) {
            auto it = cacheMap[key];
            cacheList.splice(cacheList.begin(), cacheList, it);
            cacheList.begin()->value = value;
        }else {
            if(cacheList.size() == size()) {
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(cacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        }
    }
private:
    int size;
    list<cacheNode> cacheList;
    unordered_map<int, list<cacheNode>::iterator> cacheMap;
};
