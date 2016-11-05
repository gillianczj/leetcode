typedef unordered_map<char, unordered_set<char>> graph
class Solution {
public:
    string alienOrder(vector<string>& words) {
        string ret;
        if(words.empty()) {
            return ret;
        }
        if(words.size() == 1) {
            return words[0];
        }
        graph g = makeGraph(words);
        unordered_map<char, int> inDegree = countDegree(g);
        queue<char> q;
        for(auto node : inDegree) {
            if(node.second == 0) {
                q.push(node.first);
            }
        }
        while(!q.empty()) {
            char temp = q.front();
            q.pop();
            ret.push_back(temp);
            for(auto ele : g[temp]) {
                if(--inDegree[ele] == 0) {
                    q.push(ele);
                }
            }
        }
        if(ret.size() != inDegree.size()) {
            return "";
        }
        return ret;
    }
private:
    graph makeGraph(vector<string>& words) {
        graph g;
        for(int i = 1; i < words.size(); ++i) {
            bool found = false;
            string word1 = words[i - 1], word2 = words[i];
            int l = max(word1.size(), word2.size());
            for(int i = 0; i < l; ++i) {
                if(i < word1.size() && !g.count(word1[i])) {
                    g[word1[i]] = unordered_set<char>();
                }
                if(i < word2.size() && !g.count(word2[i])) {
                    g[word2[i]] = unordered_set<char>();
                }
                if(i < word1.size() && i < word2.size() && word1[i] != word2[i] && !found) {
                    g[word1[i]].insert(word2[i]);
                    found = true;
                }
            }
        }
        return g;
    }
    unordered_map<char, int> countDegree(graph& g) {
        unordered_map<char, int> inDegree;
        for(auto node : g) {
            if(!inDegree.count(node.first));
            for(auto ele : node.second) {
                ++inDegree[ele];
            }
        }
        return inDegree;
    }
};
