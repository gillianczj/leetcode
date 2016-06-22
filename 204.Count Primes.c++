class solution {
public;
    int countPrimes(int n) {
        int count = 0;
        bool *tag = new bool[n];
        int *prime = new int[n];
        memset(tag, true, sizeof(bool) * n);
        for(int i = 2; i < n; ++i) {
            if(tag[i]) {
                prime[count++] = i;
            }
            for(int j = 0; j < count && i * prime[j] < n; ++j) {
                tag[i * prime[j]] = false;
                if(i % prime[j] == 0) {
                    break;
                }
            }
        }
        delete []tag;
        delete []prime;
        return count;
    }
};
