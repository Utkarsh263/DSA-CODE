class LFUCache {
private:
    struct Node {
        int key, value, freq;
        Node(int k, int v) : key(k), value(v), freq(1) {}
    };

    int capacity, minFreq;
    unordered_map<int, list<Node>::iterator> cache; // key → iterator to node
    unordered_map<int, list<Node>> freqMap;         // freq → list of nodes (LRU order)

    void updateFreq(int key) {
        auto it = cache[key];
        int freq = it->freq;
        Node node = *it;

        // remove from current freq list
        freqMap[freq].erase(it);
        if (freqMap[freq].empty()) {
            freqMap.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        // insert into next freq list
        node.freq++;
        freqMap[node.freq].push_front(node);
        cache[key] = freqMap[node.freq].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (capacity == 0 || cache.find(key) == cache.end()) return -1;
        updateFreq(key);
        return cache[key]->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (cache.find(key) != cache.end()) {
            cache[key]->value = value;
            updateFreq(key);
            return;
        }

        if (cache.size() == capacity) {
            // evict LFU
            auto it = freqMap[minFreq].back();
            int oldKey = it.key;
            freqMap[minFreq].pop_back();
            if (freqMap[minFreq].empty()) freqMap.erase(minFreq);
            cache.erase(oldKey);
        }

        // insert new node
        Node node(key, value);
        freqMap[1].push_front(node);
        cache[key] = freqMap[1].begin();
        minFreq = 1;
    }
};
