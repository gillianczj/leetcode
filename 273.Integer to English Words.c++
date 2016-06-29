class solution {
public:
    string numberToWords(int num) {
        const string unit[4] = {"", " Thousand", " Million", " Billion"};
        string ret;
        int part[4];
        for(int i = 0; i < 4; ++i) {
            part[i] = num % 1000;
            num = num / 1000;
            if(part[i] == 0) {
                continue;
            }
            ret = helper(part[i]) + unit[i] + ret;
        }
        return ret.size() ? ret.substr(1) : "Zero";
    }
private:
    string helper(int num) {
        const string lessTen[10] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
        const string lessTwenty[10] = {" Ten", " Eleven", " Twelve", "Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", "Eighteen", "Nineteen"};
        const string lessHundred[10] = {"", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", "Eighty", "Ninety"};
        string temp;
        int hundreds = num / 100;
        int tens = (num % 100) / 10;
        int units = (num % 100) % 10;
        if(hundreds != 0) {
            temp = temp + lessTen[hundreds] + " Hundred";
        }
        if(tens > 1) {
            temp = temp + lessHundred[tens] + lessTen[units];
        }else if(tens == 1) {
            temp = temp + lessTwenty[units];
        }else if(tens == 0) {
            temp = temp + lessTen[units];
        }
        return temp;
    }
};
