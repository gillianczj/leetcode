class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty()) {
            q.push(make_pair(v1.begin(), v1.end()));
        }
        if(!v2.empty()) {
            q.push(make_pair(v2.begin(), v2.end()));
        }
    }

    int next() {
        auto temp = q.front();
        q.pop();
        auto it = temp.first, end = temp.second;
        if(it + 1 != end) {
            q.push(make_pair(it + 1, end));
        }
        return *it;
    }

    bool hasNext() {
        return !q.empty();
    }
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator> > q;
};
