class solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C - A) * (D - B) + (G - E) * (H - F);
        if(B >= H || D <= F || C <= E || A >= G) {
            return area;
        }
        int left = max(A, E);
        int right = min(C, G);
        int top = min(D, H);
        int bottom = max(B, F);
        return area - (top - bottom) * (right - left);
    }
};
