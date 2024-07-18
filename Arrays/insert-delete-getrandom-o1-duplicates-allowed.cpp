class RandomizedCollection {
public:
    vector<int> v;
    unordered_map<int, vector<int>> mp;
    RandomizedCollection() {}

    bool insert(int val) {
        if (mp.find(val) == mp.end()) {
            v.push_back(val);
            int n = v.size() - 1;
            mp[val].push_back(n);
            return true;
        }
        v.push_back(val);
        int n = v.size() - 1;
        mp[val].push_back(n);
        return false;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) 
            return false;

        int idx = mp[val].back();
        mp[val].pop_back();

        if (mp[val].empty()) 
            mp.erase(val);

        if (idx != v.size() - 1) {
            int lastElement = v.back();
            v[idx] = lastElement;
            mp[lastElement].pop_back();
            mp[lastElement].push_back(idx);
            sort(mp[lastElement].begin(), mp[lastElement].end());
        }

        v.pop_back();
        return true;
    }

    int getRandom() {
        int n = v.size();
        int randIndex = rand() % n;
        return v[randIndex];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
