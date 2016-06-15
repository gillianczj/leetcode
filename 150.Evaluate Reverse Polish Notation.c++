class solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) {
            return 0;
        }
        stack<int> s;
        string op = "+-*/";
        for(auto a : tokens) {
            if(op.find(a) == -1) {
                s.push(atoi(a.c_str()));
            }else {
                if(s.size() < 2) {
                    return -1;
                }
                int fir = s.top();
                s.pop();
                int sec = s.top();
                s.pop();
                if(a == "+") {
                    s.push(sec + fir);
                }else if(a == "-") {
                    s.push(sec - fir);
                }else if(a == "*") {
                    s.push(sec * fir);
                }else if(a == "/") {
                    s.push(sec / fir);
                }
            }
        }
        return s.top();
    }
};
