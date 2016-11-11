#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int ret = 0;
        vector<bool> visited(10, false);
        vector<vector<int> > jump(10, vector<int>(10, 0));
        jump[1][3] = jump[3][1] = 2;
        jump[4][6] = jump[6][4] = 5;
        jump[7][9] = jump[9][7] = 8;
        jump[1][7] = jump[7][1] = 4;
        jump[2][8] = jump[8][2] = 5;
        jump[3][9] = jump[9][3] = 6;
        jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5;
        ret += helper(1, 1, 0, m, n, jump, visited) * 4;
        ret += helper(2, 1, 0, m, n, jump, visited) * 4;
        ret += helper(5, 1, 0, m, n, jump, visited);
        return ret;
    }
private:
    int helper(int num, int len, int cnt, int m, int n, vector<vector<int> >& jump, vector<bool>& visited) {
        if(len > n) {
            return cnt;
        }
        if(len >= m) {
            ++cnt;
        }
        visited[num] = true;
        for(int i = 1; i <= 9; ++i) {
            if(!visited[i] && (jump[num][i] == 0 || visited[jump[num][i]])) {
                cnt = helper(i, len + 1, cnt, m, n, jump, visited);
            }
        }
        visited[num] = false;
        return cnt;
    }
};

int main() {
    Solution a;
    int l = a.numberOfPatterns(1, 2);
    cout << l;
    return 0;
}
