class solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<int> ret;
        unordered_map<int, vector<int>> rela;
        int inDegree[numCourses] = {0};
        for(auto node : prerequisites) {
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
            ret.push_back(temp);
            for(auto n : rela[temp]) {
                --inDegree[n];
                if(inDegree[n] == 0) {
                    q.push(n);
                }
            }
        }
        if(ret.size() != numCourses) {
            ret.clear;
        }
        return ret;
    }
};
