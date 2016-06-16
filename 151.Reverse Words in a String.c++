class solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) {
            return;
        }
        stringstream d(s);
        stack<string> st;
        string ss;
        while(getline(d, ss, ' ')) {
            if(ss != "\0") {
                st.push(ss);
            }
        }
        s.clear();
        while(!st.empty()) {
            s += st.top() + " ";
            st.pop();
        }
        if(s.back() == ' ') {
            s.pop_back();
        }
    }
};
