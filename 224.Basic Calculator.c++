class solution {
public:
    int calculate(string s) {
        stack<char> ops;
        stack<int> nums;
        int curNum = 0;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(c == ' ') {//space
                continue;
            }
            if(c == '+' || c == '-' || c == '(') {
                ops.push(c);
                continue;
            }
            if(c == ')') {
                ops.pop();
            }else if(isdigit(c)) {
                curNum = curNum * 10 + c - '0';
                if(i + 1 < s.size() && isdigit(s[i + 1])) {//number not end
                    continue;
                }
                nums.push(curNum);
                curNum = 0;
            }
            if(ops.empty() || ops.top() == '(') {//cannot calculate
                continue;
            }
            int n = nums.top();
            nums.pop();
            if(ops.top() == '+') {
                nums.top() += n;
            }else if(ops.top() == '-') {
                nums.top() -= n;
            }
            ops.pop();
        }
        return nums.top();
    }
};
