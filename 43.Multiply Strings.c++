class solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty() || num2.empty()) {
            return "";
        }

        string ret(num1.size() + num2.size(), '0');//longest ret is adding two size

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());//reverse for convinence

        for(int j = 0; j < num2.size(); ++j) {
            int carry = 0;
            for(int i = 0; i < num1.size(); ++i) {
                carry += (num1[i] - '0') * (num2[j] - '0') + ret[i + j] - '0';
                ret[i + j] = carry % 10 + '0';
                carry /= 10;
            }

            if(carry) {//dont forget the last carry
                ret[num1.size() + j] = carry + '0';
            }
        }

        reverse(ret.begin(), ret.end());//reverse back

        int count;//discard beginning zeroes
        while(count < ret.size() - 1 && ret[count] == '0') {
            ++count;
        }

        ret.erase(0, count);
        return ret;
    }
};
