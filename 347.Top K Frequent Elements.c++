//priority queue
//overload comparator
//we want the min heap
struct comp {
public:
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second || (a.first < b.first && a.second == b.second);
    }
};

class solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        unordered_map<int, int> mp;
        for(int a : nums) {
            if(!mp.count(a)) {
                mp[a] = 1;
            }else {
                 ++mp[a];
            }
        }

        int n = 0;
        for(auto a : mp) {//the size of pq remains at k
            if(n < k) {
                pq.push(make_pair(a.first, a.second));
                ++n;
            }else if(a.second > pq.top().second) {
                pq.pop();
                pq.push(make_pair(a.first, a.second));
            }
        }

        vector<int> ret;
        while(!pq.empty()) {
            ret.push_back(pq.top().first);
            pq.pop();
        }

        reverst(ret.begin(), ret.end());//from max to min
        return ret;
    }
};

//without priority queue, only use vector
//we need a new data structure and overload operator <
class Node {
public:
    int num;
    int count;
    Node(int _num, int _count) : num(_num), count(_count) {}
    bool operator < (Node& obj) {
        return count < obj.count || (num < obj.num && count == obj.count);
    }
};

class solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int> mp;
        for(int a : nums) {
            if(!mp.count(a)) {
                mp[a] == 1;
            }else {
                ++mp[a];
            }
        }

        vector<Node> node;
        for(auto a : mp) {
            node.push_back(Node(a.first, a.second));
        }
        sort(node.begin(), node.end());
        
        vector<int> ret;
        for(int i = 0; i < k; ++i) {
            ret.push_back(node[i].num);
        }
        return ret;
    }
};
