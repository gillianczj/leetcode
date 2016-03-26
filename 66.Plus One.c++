class solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int carry = 1;
		int sum = 0;
		for(int i = digits.size() - 1; i >= 0; --i) {
			sum = carry + digits[i];
			carry = sum / 10;
			digits[i] = sum % 10;
		}
		//if carry is not zero
		if(carry != 0) {
			digits.insert(digits.begin(), carry);
		}

		return digits;
	}
};
