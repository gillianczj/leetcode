class soluiton {
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        unordered_map<int, vector<int>> rela;
        vector<int> inDegree(numCourses, 0);
        for(auto node in prerequisites) {
            rela[node.second].push_back(node.first);
            ++inDegree[node.first];
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            for(auto n : rela[temp]) {
                if(inDegree[n] == 0) {
                    q.push(n);
                }
            }
        }
        for(auto a : inDegree) {
            if(a != 0) {
                return false;
            }
        }
        return true;
    }
};
