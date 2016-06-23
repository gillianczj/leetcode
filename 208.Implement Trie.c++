class TrieNode {
public:
    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
    }
    bool isEnd;
    TrieNode* children[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* p = root;
        for(auto c : word) {
            int idx = c - 'a';
            if(!p->children[idx]) {
                children[idx] = new TrieNode();
            }
            p = p->children[idx];
        }
        p->isEnd = true;
    }

    bool search(string word) {
        TrieNode* p = root;
        for(auto c : word) {
            int idx = c - 'a';
            if(!p->children[idx]) {
                return false;
            }
            p = p->children[idx];
        }
        return p->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(auto c : prefix) {
            int idx = c - 'a';
            if(!p->children[idx]) {
                return false;
            }
            p = p->children[idx];
        }
        return true;
    }

private:
    TrieNode *root;
};
