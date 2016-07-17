class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.size() == 0) {
            return true;
        }
        stringstream in(preorder);
        int degree = 1;
        string temp;
        while(getline(in, temp, ',')) {
            --degree;
            if(degree < 0) {
                return false;
            }
            if(temp != "#") {
                degree += 2;
            }
        }
        return degree == 0;
    }
};
