class solution {
public:
	string addBinary(string a, string b) {
		//reverse a and b
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		//find out the maximum length
		int m = max(a.size(), b.size());
		string ret;
		//define carry-on value
		int carry = 0;
		//loop		
		for(int i = 0; i < m; ++i) {
		//read value from a
			if(i < a.size()) {
				carry += a[i];
			}
		//read value from b
			if(i < b.size()) {
				carry += b[i];
			}
			ret.push_back(carry % 2 + '0');
		//reset carry
			carry /= 2;
		}
     	//dont forget the carry
		if(carry != 0) {
			ret.push_back('1');		
		}
		//reverse the result
		reverse(ret.begin(), ret.end());
		return ret;	
	}
}
