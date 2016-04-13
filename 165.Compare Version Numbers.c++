class solution {
public:
	int compareVersion(string version1, string version2) {
		for(int i = 0, j = 0; i < version1.size() || j < version2.size(); ++i, ++j) {
			int sum1 = 0;
			while(i < version1.size() && version1[i] != '.') {
				sum1 = sum1 * 10 + version1[i++] - '0';
			}
			int sum2 = 0;
			while(j < version2.size() && version2[j] != '.') {
				sum2 = sum2 * 10 + version2[j++] - '0';
			}
			if(sum1 > sum2) {return 1;}
			else if(sum1 < sum2) {return -1;}
		}
		return 0;
	}
};
