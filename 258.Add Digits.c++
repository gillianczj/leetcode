class solution {
public:
	int addDigits(int num) {
	// wikipedia digital root formula
		if(num >= 10) {
			num = num - 9 * floor((num - 1) / 9);
		}
		return num;
	}
};
