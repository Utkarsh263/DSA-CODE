class MyHashMap {
private:
    static const int SIZE = 1000;
    vector<vector<pair<int,int>>> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        buckets.resize(SIZE);
    }

    void put(int key, int value) {
        int idx = hash(key);

        for (auto &p : buckets[idx]) {
            if (p.first == key) {
                p.second = value; // update
                return;
            }
        }

        buckets[idx].push_back({key, value});
    }

    int get(int key) {
        int idx = hash(key);

        for (auto &p : buckets[idx]) {
            if (p.first == key) {
                return p.second;
            }
        }

        return -1;
    }

    void remove(int key) {
        int idx = hash(key);

        for (int i = 0; i < buckets[idx].size(); i++) {
            if (buckets[idx][i].first == key) {
                buckets[idx].erase(buckets[idx].begin() + i);
                return;
            }
        }
    }
};
