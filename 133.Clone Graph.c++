class solution {
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if(!node) {
            return node;
        }
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
        return dfs(node, visited);
    }
private:
    UndirectedGraphNode* dfs(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited) {
        UndirectedGraphNode* ret = new UndirectedGraphNode(node->label);
        visted[node] = ret;
        for(auto a : node->neighbors) {
            if(visited.count(a)) {
                ret->neighbors.push_back(visited[a]);
            }else {
                ret->neighbors.push_back(dfs(a, visited));
            }
        }
        return ret;
    }
};
