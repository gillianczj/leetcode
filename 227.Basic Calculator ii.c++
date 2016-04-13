class solution {
public:
	int calculate(string s) {
		istringstream in("+" + s + "+");
		long long total = 0, temp = 0, n;
		char op;
		while(in >> op) {
			if(op == '+' || op == '-') {//the next operator
				total += temp;//finish previous calculation
				in >> temp;//next number
				temp *= (op == '+' ? 1 : -1);
			}else {//operator is * or / ,do the calculation right now
				in >> n;//the right number of operator
				if(op == '*') {
					temp *= n;
				}else {
					temp /= n;
				}
			}
		}
		return total;
	}
};
