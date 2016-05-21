class solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ret;

        unordered_set<string> h;
        queue<string> q;

        h.insert(s);
        q.push(s);

        bool found = false;//determine when to stop
        while(!q.empty()) {
            string temp = q.front();
            q.pop();

            if(isValid(temp)) {
                ret.push_back(temp);
                found = true;
            }

            if(found) {
                continue;
            }

            for(int i = 0; i < temp.size(); ++i) {
                if(temp[i] != '(' && temp[i] != ')') {
                    continue;
                }

                string t = temp.substr(0, i) + substr(i + 1);

                if(!h.count(t)) {
                    h.insert(t);
                    q.push(t);
                }
            }
        }
        return ret;
    }
private:
    bool isValid(string s) {
        int count = 0;
        for(auto a : s) {
            if(a == '(') {
                ++count;
            }
            if(a == ')' && count-- == 0) {
                return false;
            }
        }
        return count == 0;
    }
};
