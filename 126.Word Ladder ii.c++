class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string>& wordList) {
        vector<vector<string>> allSol;
        vector<string> sol;
        if(beginWord == endWord) {
            sol.push_back(beginWord);
            allSol.push_back(sol);
            return allSol;
        }
        wordList.insert(endWord);
        unordered_set<string> cur;
        unordered_set<string> next;
        unordered_set<string> visited;
        unordered_map<string, unordered_set<string>> parent;
        bool found = false;
        cur.insert(beginWord);
        while(!cur.empty() && !found) {
            for(auto node : cur) {
                visited.insert(node);
            }
            for(auto node : cur) {
                for(int i = 0; i < node.size(); ++i) {
                    string temp = node;
                    for(int j = 0; j < 26; ++j) {
                        if(temp[i] == 'a' + j) {
                            continue;
                        }
                        temp[i] = 'a' + j;
                        if(wordList.count(temp) && !visited.count(temp)) {
                            parent[temp].insert(node);
                            if(temp == endWord) {
                                found = true;
                            }
                            next.insert(temp);
                        }
                    }
                }
            }
            swap(cur, next);
            next.clear();
        }
        if(found) {
            findPath(allSol, sol, parent, beginWord, endWord);
        }
        return allSol;
    }
private:
    void findPath(vector<vector<string>>& allSol, vector<string>& sol, unordered_map<string, unordered_set<string>>& parent, string& beginWord, string& endWord) {
        if(endWord == beginWord) {
            sol.push_back(beginWord);
            allSol.push_back(sol);
            reverse(allSol.back().begin(), allSol.back().end());
            sol.pop_back();
            return;
        }
        sol.push_back(endWord);
        unordered_set<string> level;
        for(auto word : level) {
            findPath(allSol, sol, parent, beginWord, word);
        }
        sol.pop_back();
    }
};
