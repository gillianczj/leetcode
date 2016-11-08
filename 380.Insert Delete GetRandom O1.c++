class RandomizedSet {
public:
    RandomizedSet(){}

    bool insert(int val) {
        if(mp.count(val)) {
            return false;
        }
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if(!mp.count(val)) {
            return false;
        }
        int back = nums.back();
        mp[back] = mp[val];
        nums[mp[val]] = back;
        nums.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    unordered_map<int, int> mp;
    vector<int> nums;
};
