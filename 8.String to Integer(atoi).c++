class solution {
public:
    int myAtoi(string str) {
        bool isNeg = false;//whether the number is negative
        unsigned long ret = 0;
        int i = 0;
        while(str[i] == ' ' && i < str.size()) {
            ++i;
        }//skip the whitespaces at the beginning

        //if the first non-whitespace is not digit and + -
        if(!isdigit(str[i]) && str[i] != '+' && str[i] != '-' && i < str.size()) {
            return 0;
        }

        //if thr first non-whitespace is + or -
        if((str[i] == '-' || str[i] == '+') && i < str.size()) {
            if(!digit(str[i + 1]) && i + 1 < str.size()) {
                return 0;
            }//the next char of + or - is not digit

            if(str[i] == '-') {
                isNeg = true;
            }
            ++i;
        }

        while(isdigit(str[i]) && i < str.size()) {
            ret = ret * 10 + str[i] - '0';
            if(ret > (unsigned long) INT_MAX) {
                return isNeg ? INT_MIN : INT_MAX;
            }//overflow or not
            ++i;
        }

        return isNeg ? -(int) ret : (int) ret;
    }
};
