class solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto a : s) {
            if(a == '[' || a == '(' || a == '{') {
                stk.push(a);
            }else {
                if(stk.empty()) {
                    return false;
                }

                if((a == ']' && stk.top() != '[') || (a == ')' && stk.top() != '(') || (a == '}' && stk.top() != '{')) {
                    return false;
                } 

                stk.pop();
            }
        }

        return stk.empty();
    }
};
