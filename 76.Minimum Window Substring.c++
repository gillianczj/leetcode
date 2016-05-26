class solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.size() < t.size()) {
            return "";
        }
        vector<int> check(256, 0);//for t
        vector<int> count(256, 0);//for s
        for(auto a : t) {
            ++check[a];
        }
        int cnt = 0;
        int start = 0;
        int end;
        for(end = 0; end < s.size(); ++end) {
            if(count[s[end]] < check[s[end]]) {
                ++cnt;
            }
            ++count[s[end]];
            if(cnt == t.size()) {//first window
                break;
            }
        }
        if(end == s.size()) {
            return "";
        }
        while(start < s.size() && count[s[start]] > check[s[start]]) {//increase start
            --count[s[start++]];
        }
        int curStart = start;
        for(int i = end + 1; i < s.size(); ++i) {
            ++count[s[i]];
            while(curStart < s.size() && count[s[curStart]] > check([s[curStart]])) {//for every new end, increase start
                --count[s[curStart++]];
            }
            if(i - curStart < end - start) {//update start and end
                start = curStart;
                end = i;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
