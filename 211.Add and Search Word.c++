class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];
    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* p = root;
        for(auto c : word) {
            int idx = c - 'a';
            if(!p->children[idx]) {
                p->children[idx] = new TrieNode();
            }
            p = p->children[idx];
        }
        p->isEnd = true;
    }

    bool search(string word) {
        return helper(word, 0, root);
    }

    bool helper(string &word, int idx, TrieNode* p) {
        if(idx == word.size()) {
            return p->isEnd;
        }
        if(word[idx] == '.') {
            for(int i = 0; i < 26; ++i) {
                if(p->children[i]) {
                    if(helper(word, idx + 1, p->children[i])) {
                        return true;
                    }
                }
            }
            return false;
        }else {
            int index = word[idx] - 'a';
            if(p->children[index]) {
                return helper(word, idx + 1, p->children[index]);
            }else {
                return false;
            }
        }
    }
private:
    TrieNode* root;
};
